#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

struct node
{
  int data;
  struct node *prev, *next;
};
typedef struct node NODE;

NODE *first = NULL;
NODE *last = NULL;

void insert_beginning(int x)
{
  NODE *pnode;
  pnode = (NODE *)malloc(sizeof(NODE));
  pnode->data = x;

  if (first == NULL)
  {
    pnode->prev = pnode->next = NULL;
    first = last = pnode;
  }
  else
  {
    pnode->prev = NULL;
    first->prev = pnode;
    pnode->next = first;
    first = pnode;
  }
}

void insert_end(int x)
{
  NODE *pnode;
  pnode = (NODE *)malloc(sizeof(NODE));
  pnode->data = x;
  if (first == NULL)
  {
    pnode->prev = pnode->next = NULL;
    first = last = pnode;
  }
  else
  {
    pnode->prev = last;
    pnode->next = NULL;
    last->next = pnode;
    last = pnode;
  }
}

void insert_mid(int x, int k)
{
  NODE *pnode, *p;
  int i = 1;
  pnode = (NODE *)malloc(sizeof(NODE));
  pnode->data = x;
  p = first;
  while (i != k - 1)
  {
    p = p->next;
    i++;
  }
  pnode->next = p->next;
  pnode->prev = p;
  p->next->prev = pnode;
  p->next = pnode;
}

void deletes(int k)
{
  NODE *p;

  while (p != NULL)
  {
    if (p->data == k)
      break;
    p = p->next;
  }

  if (p == NULL)
    printf("\n Required node not found");
  else
  {
    if (p == first && p == last)
      first = last = NULL;
    else if (p == first)
    {
      first = first->next;
      first->prev = NULL;
    }
    else if (p == last)
    {
      last = last->prev;
      last->next = NULL;
    }
    else
    {
      p->next->prev = p->prev;
      p->prev->next = p->next;
    }
    free(p);
  }
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
    printf("\n Required node at %x", p);
}

void traverse_right()
{
  if (first == NULL)
    printf("\n Linked list is empty");
  else
  {
    NODE *p;
    p = first;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
    printf("\n");
  }
}

void traverse_left()
{
  if (last == NULL)
    printf("\n Linked list is empty");
  else
  {
    NODE *p;
    p = last;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->prev;
    }
    printf("\n");
  }
}

void main()
{
  int x, ch, k;

  clrscr();
  do
  {
    printf("\n Menu");
    printf("\n 1:Insert in beginning");
    printf("\n 2:Insert at end");
    printf("\n 3:Insert in middle");
    printf("\n 4:Delete node");
    printf("\n 5:Search node");
    printf("\n 6:Traverse right");
    printf("\n 7:Traverse left");
    printf("\n 8:Exit");
    printf("\n Enter your choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
      printf("\n Enter the element");
      scanf("%d", &x);
      insert_beginning(x);
      break;
    }
    case 2:
    {
      printf("\n Enter the element");
      scanf("%d", &x);
      insert_end(x);
      break;
    }
    case 3:
    {
      printf("\n Enter the element");
      scanf("%d", &x);
      printf("\n Enter the position");
      scanf("%d", &k);
      insert_mid(x, k);
      break;
    }
    case 4:
    {
      printf("\n Enter the element to be removed");
      scanf("%d", &x);
      deletes(x);
      break;
    }
    case 5:
    {
      printf("\n Enter the element to be searched");
      scanf("%d", &x);
      search(x);
      break;
    }
    case 6:
    {
      traverse_right();
      break;
    }
    case 7:
    {
      traverse_left();
      break;
    }
    case 8:
      break;
    }
  } while (ch != 8);
  getch();
}