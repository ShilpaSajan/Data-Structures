#include<stdio.h>
#include<conio.h>
#include<ctype.h>

int stack[20];
int top=-1;

void push(int x)
{
 stack[++top]=x;
}

int pop()
{
 return stack[top--];
}

void main()
{
 char input[20];
 int i=0,n1,n2,n;
 clrscr();
 printf("\nenter the postfix expression:");
 scanf("%s",input);
 while(input[i]!='\0')
 {
  if(isdigit(input[i]))
  {
   n=input[i]-48;
   push(n);
  }
  else
  {
  n1=pop();
  n2=pop();
  switch(input[i])
  {
   case '+':n=n1+n2;break;
   case '-':n=n2-n1;break;
   case '*':n=n1*n2;break;
   case '/':n=n2/n1;break;
  }
  push(n);
  }
  i++;

  }
  printf("\n result : %d",pop());
  getch();
  }
