#include<stdio.h>
#include<conio.h>
#define STACKSIZE 5
#include<stdlib.h>

struct stack
{
int top;
int items[STACKSIZE];
};

void push(struct stack *ps,int x)
{
 if(ps->top==STACKSIZE-1)
  {
   printf("\n Stack overflow.Cannot insert");
   getch();
   exit(1);
  }
  ps->items[++(ps->top)];
}

int empty(struct stack *ps)
{
 if(ps->top==-1)
  return 1;
 else
  return 0;
}

int pop(struct stack *ps)
{
 if(empty(ps))
  {
   printf("\n Stack underflow. Cannot pop");
   getch();
   exit(1);
  }
  return(ps->items[(ps->top)--]);
}

void show(struct stack s)
{
 int i;
 printf("\n Elements from the top of the stack are as shown \n");

 for(i=s.top; i>=0; i--)
 {
  printf(" %d ",s.items[i]);
 }


}

void main()
{
 int x,ch;
 struct stack s;
 s.top=-1;
 clrscr();
 do
 {
 printf("\n \n Menu");
 printf("\n 1: Push");
 printf("\n 2: Pop");
 printf("\n 3: Display");
 printf("\n 4: Exit");
 printf("\n Enter your choice");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
  {
  printf("\n Enter the element");
  scanf("%d",&x);
  push(&s,x);
  show(s);
  break;
  }
  case 2:
  {
   x=pop(&s);
   printf("\n %d poped from the stack");
   show(s);
   break;

  }

  case 3:
  {
  show(s);
  break;
  }
  case 4:
  break;
  default: printf("\n Enter a valid choice");

 }
 }
 while(ch!=4);
 getch();
}