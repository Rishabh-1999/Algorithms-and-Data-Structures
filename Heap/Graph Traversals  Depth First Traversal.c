#include <stdio.h>
#include <stdlib.h>

#define V 5    // Total number of nodes in graph

int adj_mat[V][V];    // Adjacency matrix
int visited[V]={0};    // visited array to remember the traversed nodes

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

void DFS(int i)
{
  int j;
  printf("\n%d",i);
  visited[i]=1;

  for(j=0;j<V;j++)
    if(!visited[j] && adj_mat[i][j]==1)
      DFS(j);
}

int main()
{
  int option;
  printf("\n A Program to read a Simple Graph using Adjacency Matrix. \n");
  build_graph();
  printf("Depth First Traversal of Graph starting from vertex 0 is : \n");
  DFS(0);
}
