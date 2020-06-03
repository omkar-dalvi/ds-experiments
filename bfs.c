#include <stdio.h>
#include <conio.h>
#define QUEUESIZE 20

int v, adj[10][10], visited[10];
/*
Standard queue operations
*/
struct queue
{
  int front, rear;
  int items[QUEUESIZE];
};

struct queue q;
void insert(int x)
{
  q.items[++(q.rear)] = x;
}

int empty()
{
  if (q.rear < q.front)
    return 1;
  else
    return 0;
}

int removes()
{
  return (q.items[(q.front)++]);
}

/*
Queue operations over.
*/

int sequential(int key)
{
  int i = 0;
  while (i < QUEUESIZE)
    if (key == q.items[i])
      return i;
    else
      i++;
  return -1;
}

void bsk(int k);

void main()
{
  int i, j;
  printf("\n Enter the number of vertices");
  scanf("%d", &v);
  for (i = 1; i <= v; i++)
    for (j = 1; j <= v; j++)
    {
      printf("\n Is %d adjacent to %d", j, i);
      printf("\n Enter 1 for yes and 0 for no");
      scanf("%d", &adj[i][j]);
    }

  for (i = 1; i <= v; i++)
    visited[i] = 0;
  printf("\n The breadth first search is as follows \n ");
  for (i = 1; i <= v; i++)
  {
    if (visited[i] == 0)
      bfs(i);
  }

  getch();
}

void bfs(int k)

{
  int j;
  q.rear = -1;
  q.front = 0;
  insert(k);
  while (!empty())
  {
    k = removes();
    visited[k] = 1;
    printf("%d ", k);
    for (j = 1; j <= v; j++)
      if (adj[k][j] == 1)
        if (visited[j] == 0 && sequential(j) == -1)
          insert(j);
  }
}