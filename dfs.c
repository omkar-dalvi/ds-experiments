#include <stdio.h>
#include <conio.h>

int v, adj[10][10], visited[10];

void dfs(int k)
{
  int j;
  visited[k] = 1;
  printf("%d ", k);

  for (j = 1; j <= v; j++)
    if (adj[k][j] == 1)
      if (visited[j] == 0)
        dfs(j);
}

void main()
{
  int i, j;
  clrscr();
  for (i = 1; i <= v; i++)
    for (j = 1; j <= v; j++)
    {
      printf("\n Is %d adjacent to %d ", j, i);
      printf("\n Enter 1 if yes and 0 if no");
      scanf("%d", &adj[i][j]);
    }
  for (i = 1; i <= v; i++)
    visited[i] = 0;
  printf("\n Depth first search is as follows. \n");

  for (i = 1; i <= v; i++)
    if (visited[i] == 0)
      dfs(i);
  getch();
}