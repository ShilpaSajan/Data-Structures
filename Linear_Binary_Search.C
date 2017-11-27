#include<stdio.h>
#include<conio.h>
void sort(int ar[],int n){
 //selection sort 
 int i,j,temp;
 for(i=0;i<n;++i){
  for(j=i+1;j<n;++j){
   if(ar[i]>ar[j]){
    temp = ar[i];
    ar[i]=ar[j];
    ar[j]=temp;
   }
  }
 }
}
void main(){
  int ch,ar[20],n,i,first,last,mid,num;
  clrscr();
  printf("How many elements?:");
  scanf("%d",&n);
  printf("\nEnter elements:");
  for(i=0;i<n;++i)
   scanf("%d",&ar[i]);
  while(1){
  printf("Which element to search for?:");
  scanf("%d",&num);
  printf("\n1.Linear Search\n2.Binary Search\nSelect choice:");
  scanf("%d",&ch);
  switch(ch){
   case 1: //Linear Search
    for(i=0;i<n;++i){
     if(ar[i]==num){
      printf("%d found at position %d",num,i+1);break;
     }else{
      if(i+1==n)
       printf("Element not found!");
     }
    }
    break;
   case 2: //Binary Search
    sort(ar,n);
    first=0;
    last=n-1;
    mid=(first+last)/2;
    while(first<=last){
     if(ar[mid]==num){
      printf("%d found at position %d",num,mid+1);break;
     }else if(num<ar[mid]){
      last=mid-1;
     }else{
      first=mid+1;
     }
     mid=(first+last)/2;
    }
    if(first>last)
     printf("Element not found!");
    break;
   default:
    printf("Invalid Choice!");
  }
  printf("\nSearch again? (y=1,n=0) : "); //asking user to run the program again !!
  scanf("%d",&ch);
  if(ch==0)
   break;
 }
 getch();
}
