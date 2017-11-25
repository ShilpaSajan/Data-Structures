#include<stdio.h>
#include<conio.h>
int stack[50],ch,ch1,n,top,top1,top2,x,i;
void push()
{
  if(top==n-1)
    printf("\nStack Overflow");
  else
  {
	printf("\nvalue:");
	scanf("%d",&x);
	top++;
	stack[top]=x;
  }
}
void pop()
{
  if(top<=-1)
    printf("\nStack Underflow");
  else
  {
	printf("\npopped element is: %d",stack[top]);
    top--;
  }
}
void display()
{
  if(top>=0)
  {
    printf("\nThe elements are:");
    for(i=top;i>=0;i--)
      printf("\n %d",stack[i]);
  }
  else
  {
    printf("\nStack is empty");
  }
}
void push1()
{
  if(top1+1==top2)
   {	printf("\nStack full");
	return; }
  else
  {
	printf("\nvalue:");
	scanf("%d",&x);
	stack[++top1]=x;
  }
}
void push2()
{
  if(top2-1==top1)
  {
	printf("\nStack Overflow");
	return;
   }
  else
  {
	printf("\nvalue:");
	scanf("%d",&x);
	stack[--top2]=x;
  }
}
void pop1()
{
  if(top1>=0)
  {
	int popped_value=stack[top1--];
	printf("%d is popped from stack 1",popped_value);
  }
  else
	printf("\nStack Underflow");
}
void pop2()
{
  if(top2<=n-1)
  {
	int popped_value=stack[top2++];
	printf("%d is popped from stack 2",popped_value);
  }
  else
	printf("\nStack Underflow");
}
void display1()
{
  printf("\nElements are:");
  for(i=top1;i>=0;i--)
	printf("%d\t",stack[i]);
}
void display2()
{
  printf("\nElements are:");
  for(i=top2;i<=n-1;i++)
	printf("%d\t",stack[i]);
}
int main()
{
  int o;
  clrscr();
  start:
  printf("\nOPTIONS \n\n 1)Stack\n 2)Multiple Stack");
  printf("\n \nEnter your choice : ");
  scanf("%d",&ch1);
  if(ch1==1)
  {
	top=-1;
	printf("\n\nEnter the max size of stack:");
	scanf("%d",&n);
	printf("\nMENU \n \n 1)PUSH \n 2)POP \n 3)PRINT\n 4)EXIT");
	do
	{
	  printf("\nEnter your choice : ");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	case 1:push();
		   break;
	case 2:pop();
		   break;
	case 3:display();
		   break;
	case 4:printf("\nExit");
		   break;
	default:printf("\nInvalid choice");
		break;
	  }
	}
	while( ch!=4);
  }
  else if(ch1==2)
  {
	top1=-1;
	printf("\nEnter the size : ");
	scanf("%d",&n);
	top2=n;
	printf("\nMENU\n\n 1)Push from stack 1\n 2)Pop from stack 1\n 3)Print from stack 1");
	printf("\n 4)Push from stack 2\n 5)Pop from stack 2\n 6)Print stack 2\n 7)Exit\n");
	do
	{
	  printf("\nEnter your choice :");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	case 1:push1();
		   break;
	case 2:pop1();
		   break;
	case 3:display1();
		   break;
	case 4:push2();
		   break;
	case 5:pop2();
		   break;
	case 6:display2();
		   break;
	case 7:printf("\nExit");
		   break;
	default:printf("\nInvalid choice");
		break;
	  }
	}
	while(ch!=7);
  }
  else
	printf("\n Invalid choice ");
  printf("\n \n`prev menu (yes=1/ no=0)");
  scanf("%d",&o);
  if(o==1)
  goto start;
  return 0;
}