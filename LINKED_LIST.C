// Program to implement Linked List using C Programming

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void del_begin();
void del_end();
void del_pos();

struct node{
	int info;
	struct node *next;
	};
struct node *start=NULL;


void create(void)
{
 struct node *temp,*ptr;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
   {
     printf("\n Out of Memory space.");
     exit(0);
   }
 printf("\n Enter the data value for node. \t");
 scanf("%d", &temp->info);
 temp->next=NULL;
 if(start== NULL)
     start=temp;
 else
    {
     ptr=start;
     while(ptr->next != NULL)
	 ptr=ptr->next;
     ptr->next=temp;
    }
 }

 void display()
 {
   struct node *ptr;
   if(start == NULL)
     {
       printf("\n List is empty.");
       return;
     }
   else
    {
     ptr=start;
     printf("\n The list elements are \n");
     while(ptr != NULL)
       { printf("%d \t", ptr->info);
	 ptr=ptr->next;
       }
    }
}

void insert_begin()
{
 struct node * temp;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
   {
     printf("\n Out of Memory space.");
     return;
   }
 printf("\n Enter the data value for node. \t");
 scanf("%d", &temp->info);
 temp->next=NULL;
 if(start== NULL)
     start=temp;
 else
    {
     temp->next=start;
     start=temp;
    }
 }

void insert_end()
{struct node *temp,*ptr;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
   {
     printf("\n Out of Memory space.");
     return;
   }
 printf("\n Enter the data value for node. \t");
 scanf("%d", &temp->info);
 temp->next=NULL;
 if(start== NULL)
     start=temp;
 else
    {
     ptr=start;
     while(ptr->next != NULL)
       {
	 ptr=ptr->next;
       }
     ptr->next=temp;
    }
}
void insert_pos()
{ struct node *temp,*ptr;
 int i,pos;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
   {
     printf("\n Out of Memory space.");
     return;
   }
 printf("\n Enter the position of the new node to be inserted.\t");
 scanf("%d", &pos);
 printf("\n Enter the data value for node. \t");
 scanf("%d", &temp->info);
 temp->next=NULL;
 if( pos==0)
     {
      temp->next=start;
      start=temp;
     }
 else
    { for(i=0,ptr=start;i<pos-1;i++)
      {
     ptr=ptr->next;
     if(ptr == NULL)
       { printf("\n Position not found.");
	 return;
       }
      }
     temp->next=ptr->next;
     ptr->next=temp;
    }
 }

void del_begin()
{
 struct node *ptr;
 if (ptr==NULL)
    {
    printf("\n List is empty.");
    return;
    }
 else
    {
     ptr=start;
     start=start->next;
     printf("\n Deleted element is %d",ptr->info);
     free(ptr);
    }
 }
 void del_end()
 {
 struct node *temp, *ptr;
 if( start==NULL)
   {
   printf("\n List is empty.");
   exit(0);
   }
 else if(start->next==NULL)
   {
    ptr=start;
    start=NULL;
    printf("\n Deleted element is %d.",ptr->info);
    free(ptr);
   }
 else
  { ptr=start;
  while(ptr->next != NULL)
   {
    temp=ptr;
    ptr=ptr->next;
   }
  temp->next=NULL;
  printf("\n Deleted element is %d",ptr->info);
  free(ptr);
  }
}

void del_pos()
{
 struct node *temp,*ptr;
 int i,pos;
 if(start==NULL)
   {
     printf("\n List is empty.");
     exit(0);
   }
 else
 {
 printf("\n Enter the position of the node to be deleted.\t");
 scanf("%d", &pos);
 if( pos==0)
     {
     ptr=start;
     start=start->next;
     printf("\n Deleted element is %d",ptr->info);
     free(ptr);
     }
 else
    { ptr=start;
    for(i=0;i<pos;i++)
     {
      temp=ptr;
      ptr=ptr->next;
      if(ptr==NULL)
       { printf("\n position not found.");
	 return;
       }
     }
    temp->next=ptr->next;
    printf("Deleted element is %d",ptr->info);
    free(ptr);
    }
 }
}
void main()
{
 int choice;
 clrscr();
 while(1) {
	printf("\n Single Linked List Operations");
	printf("\n");
	printf("\n 1.Create a linked list. \n 2.Display the linked list.\n 3.Insertion at the begining.\n 4.Insertion at the end. \n 5.Insertion at any position.\n 6.Deletion at the begining. \n 7.Deletion at the end. \n 8.Deletion at any position.\n 9.Exit ");
	printf("\n\n Enter your choice.");
	scanf("%d",&choice);
	switch(choice)
	 {
		case 1: create();
			display();
			break;
		case 2: display();
			break;
		case 3: insert_begin();
			display();
			break;
		case 4: insert_end();
			display();
			break;
		case 5: insert_pos();
			display();
			break;
		case 6: del_begin();
			display();
			break;
		case 7: del_end();
			display();
			break;
		case 8: del_pos();
			display();
			break;
		case 9: exit(0);
			break;
		default: printf("\n Enter a valid choice.");
	 }

 getch();

}}  // End of Program
