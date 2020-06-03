#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left, *right;
};
typedef struct node NODE;

NODE *root = NULL;

void insert(int x)
{
  NODE *pnode;
  pnode = (NODE *)malloc(sizeof(NODE));
  pnode->data = x;
  pnode->left = pnode->right = NULL;

  if (root == NULL)
    root = pnode;
  else
  {
    NODE *follow, *p;
    p = root;
    follow = NULL;
    while (p != NULL)
    {
      follow = p;
      if (pnode->data < p->data)
        p = p->left;
      else
        p = p->right;
    }
    if (pnode->data < follow->data)
      follow->left = pnode;
    else
      follow->right = pnode;
  }
}

void deletes(int k)
{
  NODE *follow, *p, *t, *f;
  p = root;
  follow = NULL;
  while (p != NULL)
  {
    if (p->data == k)
      break;
    follow = p;
    if (k < p->data)
      p = p->left;
    else
      p = p->right;
  }
  if (p == NULL)
    printf("\n Required node not founds");
  else
  {
    if (p->left == NULL)
      if (p != root)
        if (follow->left == p)
          follow->left = p->right;
        else
          follow->right = p->right;
      else
        root = p->right;

    else if (p->right == NULL)
      if (p != root)
        if (follow->left == p)
          follow->left = p->right;
        else
          follow->right = p->right;
      else
        root = p->right;
    else
    {
      t = p->right;
      f = p;
      while (t->left != NULL)
      {
        f = t;
        t = t->left;
      }
      p->data = t->data;
      if (f != p)
        f->left = t->right;
      else
        f->right = t->right;
      p = t;
    }
    free(p);
  }
}

void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void main()
{
  int x, ch;

  clrscr();
  do
  {
    printf("\n Menu");
    printf("\n 1:Insert");
    printf("\n 2:Delete");
    printf("\n 3:Inorder traversal 4 for exit");
    printf("\n Enter your choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
      printf("\n Enter the data element");
      scanf("%d", &x);
      insert(x);
      break;
    }
    case 2:
    {
      printf("\n Enter the number to be deleted");
      scanf("%d", &x);
      deletes(x);
      break;
    }
    case 3:
    {
      inorder(root);
      break;
    }
    case 4:
    {
      break;
    }
    }
  } while (ch != 4);
  getch();
}