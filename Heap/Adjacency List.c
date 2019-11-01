#include <stdio.h>
#include <stdlib.h>

#define V 3    // Total number of nodes in graph

#define new_node (struct graph_node*)malloc(sizeof(struct graph_node))

struct graph_node
{
  int vertex;
  struct graph_node *next;
};

void read_graph(struct graph_node *adj_list[V])
{
  int i, j;
  int reply;
  struct graph_node *p, *c;
  for (i = 0; i < V; i++)
  {
    for (j = 0; j < V; j++)
    {
      if (i != j)
      {
        c = new_node;
        c->vertex = j;
        c->next = NULL;
        if(adj_list[i] == NULL)
          adj_list[i] = c;
        else
        {
          p = adj_list[i];
          while(p->next != NULL)
            p = p->next;
          p->next = c;
        }
      }
    }
  }
}

int build_graph()
{
  struct graph_node *adj_list[V], *p;
  int deg=0, i, j;
  for(i = 1; i <= V; i++)
    adj_list[i] = NULL;
  read_graph(adj_list);

  printf("\n Vertex \t Adjacent to ");
  for(i = 0; i < V; i++ )
  {
    p = adj_list[i];
    printf("\n %5d \t\t ", i);
    while(p != NULL)
    {
      deg++;
      printf("%d, ", p->vertex);
      p = p->next;
    }
    printf("\n");
  }

  printf("\n\nTotal Edges in Graph are: %d\n",deg/2);
  return 1;
}

int main()
{
  int option;
  printf("\n A Program to read a Simple Graph using Adjacency List. \n");
  build_graph();
}

