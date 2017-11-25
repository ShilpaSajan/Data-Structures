#include<stdio.h>
#include<conio.h>
#include<alloc.h>
int front,rear,n,no,ch,ch1,x,a[20],i;
struct node{
int d;
struct node*ptr;
}*front1=NULL,*rear1=NULL;

void enqueue(int data)
{
struct node*new;
new=(struct node *)malloc(sizeof(struct node));
new->d=data;
new->ptr=NULL;
if(front1==NULL)
	front1=rear1=new;
else
{
	rear1->ptr=new;
	rear1=new;
}
}
void dequeue()
{
if(front1==NULL)
{
	printf("Deletion not possible");
	return;
}
else
{
	struct node*temp=front1;
	front1=front1->ptr;
	printf("Deleted value is %d",temp->d);
	free(temp);
}
}
void display1()
{
if(front1==NULL)
	printf("QUEUE IS EMPTY");
else
{
	struct node*temp=front1;
	while(temp->ptr!=NULL)
	{
		printf("%d",temp->d);
		temp=temp->ptr;
	}
	printf("%d",temp->d);
}
}
void push()
{
if(rear==(n-1))
	printf("INSERTION NOT POSSIBLE");
else if(rear==-1)
{
	front=0;
	rear=0;
	printf("ENTER THE DATA");
	scanf("%d",&x);
	a[rear]=x;
}
else
{
	rear++;
	printf("Enter the data");
	scanf("%d",&x);
	a[rear]=x;
}
}
void pop()
{
if((front==-1)||(front>rear))
{
	printf("DELETION NOT POSSIBLE");
	front=-1;
	rear=-1;
}
else
{
	printf("Deleted item is %d",a[front]);
	front++;
}
}
void display()
{
if(front==-1)
	printf("QUEUE IS EMPTY");
else
{
	printf("The elements are:");
	for(i=front;i<=rear;i++)
		printf("%d",a[i]);
}
}
void main()
{
clrscr();
printf("\n 1.array \n 2.linkedlist");
printf("Enter your choice:");
scanf("%d",&ch1);
if(ch1==1)
{
	printf("Enter the size of the array:");
	scanf("%d",&n);
	front=-1;
	rear=-1;
	printf("\n 1.INSERTION \n 2.DELETION \n 3.PRINT \n 4. EXIT \n ");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("EXIT");
			break;
		default:
			printf("INVALID CHOICE");
			break;
		}
	}
while(ch!=4);
}
else if(ch1==2)
{
	printf("\n 1.INSERTION \n 2.DELETION \n 3.PRINT  \n 4.EXIT");
	do
	{       printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter the data");
			scanf("%d",&no);
			enqueue(no);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display1();
			break;
		case 4:
			printf("EXIT");
			break;
		default:
			printf("Invalid entry");
			break;
	}
}
while(ch!=4);
}
else
{
	printf("Invalid entry");
}
getch();
}
