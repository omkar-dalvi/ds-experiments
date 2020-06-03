#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

struct node
{
  int data;
  struct node *next;
};
typedef struct node NODE;

NODE *first = NULL;

void insert_beginning(int x)
{
  NODE *pnode;
  pnode = (NODE *)malloc(sizeof(NODE));
  pnode->data = x;
  if (first == NULL)
  {
    first = pnode;
    pnode->next = NULL;
  }
  else
  {
    pnode->next = first;
    first = pnode;
  }
}

void insert_end(int x)
{
  NODE *pnode, *p, *follow;
  pnode = (NODE *)malloc(sizeof(NODE));
  pnode->data = x;

  if (first == NULL)
  {
    first = pnode;
    pnode->next = NULL;
  }
  else
  {
    p = first;
    follow = NULL;
    while (p != NULL)
    {
      follow = p;
      p = p->next;
    }
    follow->next = pnode;
    pnode->next = NULL;
  }
}

void insert_mid(int x, int k)
{
  NODE *pnode, *p;
  int i;
  pnode = (NODE *)malloc(sizeof(NODE));
  pnode->data = x;

  if (first == NULL)
  {
    first = pnode;
    pnode->next = NULL;
  }
  else
  {
    i = 1;
    p = first;
    while (i != k - 1)
    {
      p = p->next;
      i++;
    }
    pnode->next = p->next;
    p->next = pnode;
  }
}

void show()
{
  NODE *p;
  printf("\n The elements of the linked list are as follows \n");
  p = first;
  while (p != NULL)
  {
    printf("%d  ", p->data);
    p = p->next;
  }
}

void deletes(int k)
{
  NODE *p, *follow;
  p = first;
  follow = NULL;
  while (p != NULL)
  {
    if (p->data == k)
      break;
    follow = p;
    p = p->next;
  }

  if (p == first)
  {
    first = first->next;
  }
  else
  {
    follow->next = p->next;
  }
  free(p);
}

void search(int k)
{
  NODE *p;
  p = first;
  while (p != NULL)
  {
    if (p->data == k)
      break;
    p = p->next;
  }
  if (p == NULL)
    printf("\n Required node not found");
  else
    printf("\n Required node is present at address %x", p);
}

void main()
{
  int ch, x, k;
  clrscr();
  do
  {
    printf("\n Menu");
    printf("\n 1:Insert at beginning");
    printf("\n 2:Insert at end");
    printf("\n 3:Insert in middle");
    printf("\n 4:Delete node");
    printf("\n 5:Search node");
    printf("\n 6:Traverse");
    printf("\n 7:exit");

    printf("\n Enter your choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
      printf("\n Enter the element");
      scanf("%d", &x);
      insert_beginning(x);
      show();
      break;
    }
    case 2:
    {
      printf("\n Enter the element");
      scanf("%d", &x);
      insert_end(x);
      show();
      break;
    }
    case 3:
    {
      printf("\n Enter the element");
      scanf("%d", &x);
      printf("\n Enter the position");

      scanf("%d", &k);
      insert_mid(x, k);
      show();
      break;
    }
    case 4:
    {
      printf("\n Enter the element to be deleted");
      scanf("%d", &x);
      deletes(x);
      show();
      break;
    }
    case 5:
    {
      printf("\n Enter the data of the node");
      scanf("%d", &x);
      search(x);
      break;
    }
    case 6:
    {
      show();
      break;
    }
    case 7:
      break;
    }
  } while (ch != 7);
  getch();
}