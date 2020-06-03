#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define QUEUESIZE 5

struct queue
{
  int items[QUEUESIZE];
  int front, rear;
};
struct queue q;

void insert(int x)
{
  if (q.front == ((q.rear + 1) % QUEUESIZE) && q.rear != -1)
  {
    printf("\ n Queue overflow. Cannot insert");
    exit(1);
    getch();
  }
  if (q.rear == QUEUESIZE - 1)
    q.rear = 0;
  else
    (q.rear)++;
  q.items[q.rear] = x;
}

int empty()
{
  if (q.rear == -1 && q.front == 0)
    return 1;
  else
    return 0;
}

int removes()
{
  int t;
  if (empty())
  {
    printf("\n Queue underflow.Cannot remove");

    getch();
    exit(1);
  }
  t = q.items[q.front];
  if (q.front == QUEUESIZE - 1)
    q.front = 0;
  else if (q.front == q.rear)
  {
    q.front = 0;
    q.rear = -1;
  }
  else
    (q.front)++;

  return t;
}

void show()
{
  int i;
  if (q.rear != -1)
  {
    printf("\n The elements of queue from front are as follows \n");
    if (q.front <= q.rear)
    {
      for (i = q.front; i <= q.rear; i++)
      {
        printf("%d ", q.items[i]);
      }
    }
    if (q.front > q.rear)
    {
      for (i = q.front; i < QUEUESIZE; i++)
        printf("%d ", q.items[i]);
      for (i = 0; i <= q.rear; i++)
        printf("%d ", q.items[i]);
    }
  }
}

void main()
{
  int x, ch;
  q.front = 0;
  q.rear = -1;
  clrscr();
  do
  {
    printf("\n Menu");
    printf("\n 1: Insert");
    printf("\n 2: Remove");
    printf("\n 3: Display");
    printf("\n 4: Exit");
    printf("\n Enter your choice ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
      printf("\n Enter the element ");
      scanf("%d", &x);
      insert(x);
      show();
      break;
    }
    case 2:
    {
      x = removes();
      printf("\n %d is removed", x);
      show();
      break;
    }
    case 3:
      show();
      break;
    case 4:
      break;
    default:
      printf("\n Enter a valid input");
    }
  } while (ch != 4);
  getch();
}
