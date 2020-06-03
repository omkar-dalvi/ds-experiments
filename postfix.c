#include <stdio.h>
#include <conio.h>
char infix[10], postfix[10], stack[10];
int top = -1, j = 0;

int pre(char c)
{
  if (c == '(')
    return 4;
  else if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;

  return -1;
}

int isOperand(char c)
{

  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}

void stackToPost()
{
  postfix[j] = stack[top];
  j++;
  top--;
}

void main()
{
  int i;
  char ce;
  clrscr();
  printf("\n Enter the infix expression");
  gets(infix);
  /*
 stack is for operators top is for stack
 postfix is for final expression j is for postfix

 */

  for (i = 0; infix[i] != '\0'; i++)
  {
    ce = infix[i];
    if (isOperand(ce))
    {
      postfix[j] = ce;
      j++;
    }
    else
    {
      if (top == -1 || ce == '(')
      {
        top++;
        stack[top] = ce;
      }
      else if (ce == ')')
      {
        while (stack[top] != '(')
        {
          stackToPost();
        }
        top--; /* Removing the ( */
      }
      else if (pre(ce) > pre(stack[top]))
      {
        top++;
        stack[top] = ce;
      }
      else if (pre(ce) <= pre(stack[top]))
      {
        while (pre(ce) <= pre(stack[top]))
        {
          stackToPost();
        }
        top++; /* For inserting ce */
        stack[top] = ce;
      }
    }
  }

  while (top != -1)
  {
    stackToPost();
  }
  printf("\n The postfix expression is %s", postfix);
  getch();
}