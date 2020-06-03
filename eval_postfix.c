#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define STACKSIZE 50

struct stack
{
  int top;
  float items[STACKSIZE];
};

void push(struct stack *ps, float x)
{
  ps->items[(++(ps->top))] = x;
}

float pop(struct stack *ps)
{
  return (ps->items[(ps->top)--]);
}

float oper(char c, float op1, float op2)
{
  switch (c)
  {
  case '+':
  {
    return (op1 + op2);
  }
  case '-':
  {
    return (op1 - op2);
  }
  case '*':
  {
    return (op1 * op2);
  }
  case '/':
  {
    return (op1 / op2);
  }
  case '^':
  {
    return (pow(op1, op2));
  }
  default:
    printf("\n Enter a valid expression");
    exit(1);
  }
}

int isOperand(char c)
{
  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}

float evaluate(char e[])
{
  int i;
  float op1, op2, x, value;
  struct stack s;
  s.top = -1;

  for (i = 0; e[i] != '\0'; i++)
  {
    if (isOperand(e[i]))
    {
      x = e[i] - '0';
      push(&s, x);
    }
    else
    {
      op2 = pop(&s);
      op1 = pop(&s);
      value = oper(e[i], op1, op2);
      push(&s, value);
    }
  }
  return (pop(&s));
}

void main()
{
  char e[50];
  clrscr();
  printf("\n Enter the expression");
  gets(e);
  printf("\n The value of the expression is %f", evaluate(e));

  getch();
}