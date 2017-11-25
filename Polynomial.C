#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
		float coef;
		int expo;
		struct node *link;
	   };

struct node *create(struct node *);
struct node *insert_s(struct node *,float,int);
struct node *insert(struct node *,float,int);
void display(struct node *ptr);
void polyadd(struct node *, struct node *);
void polymult(struct node *, struct node *);

void main()
{
int choice;
struct node *start1=NULL,*start2=NULL;
clrscr();
printf("\n Enter the first polynomial: \n");
start1=create(start1);
display(start1);
printf("\n Enter the second polynomial: \n");
start2=create(start2);
display(start2);
printf("\n Select the operation. \n 1.Add the polynomials. \n 2. Multiply the polynomials. \n 3. Exit");
scanf("%d",&choice);
switch(choice)
{
  case 1 : polyadd(start1,start2);
	   break;
  case 2 : polymult(start1,start2);
	   break;
  case 3 : exit(0);
	   break;
  default : printf("\n Enter a valid choice");
	    break;
}
getch();
}

struct node *create(struct node *start)
{
int i,n,ex;
float co;
printf("\n Enter the no of terms: \t");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\n Enter coeff for term %d",i);
scanf("%f",&co);
printf("\n Enter exp for term %d",i);
scanf("%d",&ex);
start=insert_s(start,co,ex);
}
return start;
}

struct node *insert_s(struct node *start,float co, int ex)
{
struct node *ptr, *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->coef=co;
temp->expo=ex;
if(start==NULL || ex> start->expo)
  {
   temp->link=start;
   start=temp;
  }
else
  {
   ptr=start;
   while(ptr->link != NULL && ptr->link->expo >=ex)
	ptr=ptr->link;
   temp->link=ptr->link;
   ptr->link=temp;
   }
return start;
}
struct node *insert(struct node *start,float co, int ex)
{
struct node *ptr, *temp;
temp->coef=co;
temp->expo=ex;
if(start==NULL)
  {
   temp->link=start;
   start=temp;
  }
else
  {
   ptr=start;
   while(ptr->link != NULL)
	ptr=ptr->link;
   temp->link=ptr->link;
   ptr->link=temp;
   }
return start;
}
void display(struct node *ptr)
{
if(ptr==NULL)
  {
  printf("\n Zero polynomial");
  return;
  }
while(ptr != NULL)
 {
  printf("%.1fx^%d",ptr->coef,ptr->expo);
  ptr=ptr->link;
  if( ptr != NULL)
	printf("+");
  else
	printf("\n");
 }
  }

void polyadd(struct node *p1, struct node *p2)
{
struct node *start3;
start3=NULL;
while(p1 != NULL && p2 != NULL)
  {
    if(p1->expo > p2->expo)
       {
	start3=insert(start3,p1->coef,p1->expo);
	p1=p1->link;
       }
    else if(p2->expo > p1->expo)
      {
       start3=insert(start3,p2->coef, p2->expo);
       p2=p2->link;
       }
    else if(p2->expo == p1->expo)
      {
       start3=insert(start3,p2->coef+p1->coef, p2->expo);
       p2=p2->link;
       p1=p1->link;
       }
 }
while(p1 != NULL)
 {
  start3=insert(start3,p1->coef,p1->expo);
  p1=p1->link;
 }
while(p2 != NULL)
 {
       start3=insert(start3,p2->coef, p2->expo);
       p2=p2->link;
       }
printf("\n Added Polynomial is ");
display(start3);
 }
 void polymult(struct node *p1, struct node *p2)
{
struct node *start3;
struct node *p2_beg=p2;
start3=NULL;
if(p1==NULL || p2==NULL)
 { printf("Multiplied polynomial is zero polynomial.");
    return;
 }
while(p1 != NULL)
{
 p2=p2_beg;
 while(p2 != NULL)
    {  start3=insert(start3,p2->coef*p1->coef, p2->expo+p1->expo);
       p2=p2->link;
    }
       p1=p1->link;
   }
printf("\n The multiplied polynomial is : ");
display(start3);
}

