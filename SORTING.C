#include<stdio.h>
#include<conio.h>
void main(){
 int ar[20],n,i,j,ch,temp,num;
 clrscr();
 printf("Enter size:");
 scanf("%d",&n);
 printf("\nEnter elements:");
 for(i=0;i<n;++i)
  scanf("%d",&ar[i]);
 printf("1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\nEnter Choice:");
 scanf("%d",&ch);
 switch(ch){
  case 1:  //Bubble
   for(i=0;i<n;++i){
    for(j=0;j<n-i-1;++j){
     if(ar[j]>ar[j+1]){
      temp = ar[j];
      ar[j] = ar[j+1];
      ar[j+1] = temp;
     }
    }
   }
   break;
  case 2:
  //Selection
  for(i=0;i<n-1;++i){
   for(j=i+1;j<n;++j){
    if(ar[i]>ar[j]){
     temp = ar[i];
     ar[i] = ar[j];
     ar[j] = temp;
    }
   }
  }
  break;
  case 3:
  //Insertion
  for(i=1;i<n;++i){
    num = ar[i];
    j=i-1;
    while(j>=0 && num<ar[j]){
     temp=ar[j];
     ar[j]=ar[j+1];
     ar[j+1]=temp;
     --j;
    }
  }
  break;
  default:
  printf("Invalid Choice!");
 }
 printf("\nSorted array is\n");
 for(i=0;i<n;++i)
  printf("%d ",ar[i]);
 getch();
}