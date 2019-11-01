#include <stdio.h>
#include <stdlib.h>

#define V 4

int adj_mat[V][V];
int visited[V]={0};
int queue[V+1], front = -1,rear = -1;

void insert_queue(int vertex)
{
  if(rear != V-1)
  {
    if(front == -1)
      front = 0;
    rear = rear+1;
    queue[rear] = vertex;
  }
}

int isEmpty_queue()
{
  if(front == -1 || front > rear)
    return 1;
  else
    return 0;
}

int delete_queue()
{
  int delete_item;
  if(front == -1 || front > rear)
  {
    printf("Queue Underflow\n");
    exit(1);
  }

  delete_item = queue[front];
  front = front+1;
  return delete_item;
}

void read_graph()
{
  int i, j;
  int reply;
  for (i = 0; i < V; i++)
  {
    for (j = 0; j < V; j++)
    {
      if (i == j)
      {
        adj_mat[i][j] = 0;
        continue;
      }
      if (i != j)
        adj_mat[i][j] = 1;
      else
        adj_mat[i][j] = 0;
    }
  }
}

int build_graph()
{
  int deg=0, i, j;
  read_graph();
  printf("\n\n ADJACENCY MATRIX\n\t");
  for (i = 0; i < V; i++)
    printf("%d\t",i);
  printf("\n");
  for (i = 0; i < V; i++)
  {
    printf("\n%d\t",i);
    for (j = 0; j < V; j++)
    {
      printf("%d\t", adj_mat[i][j]);
      if(adj_mat[i][j]) deg++;
    }
  }
  printf("\n\nTotal Edges in Graph are: %d\n",deg/2);
  return 1;
}

void BFS(int v)
{
  int i;
  insert_queue(v);
  while(!isEmpty_queue())
  {
    v = delete_queue();
    printf("\n%d",v);
    visited[v] = 1;
    for(i=0; i<V; i++)
      if(adj_mat[v][i] == 1 && !visited[i])
        insert_queue(i);
  }
}

int main()
{
  int option;
  printf("\n A Program to read a Simple Graph using Adjacency Matrix. \n");
  build_graph();
  printf("Breadth First Traversal of Graph starting from vertex 0 is : \n");
  BFS(0);
}
