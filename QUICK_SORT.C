#include<stdio.h>
#include<conio.h>
int partition(int arr[],int low,int high){
 int pivot = arr[high],i = low-1,temp,j;
 for(j=low;j<=high;++j){
  if(arr[j]<pivot){
    i++;
    temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
 }
 temp = pivot;
 arr[high]=arr[i+1];
 arr[i+1]=temp;
 return (i+1);

}

void quicksort(int arr[],int low,int high){
int pi;
 if(low<high){
  pi=partition(arr,low,high);
  quicksort(arr,low,pi-1);
  quicksort(arr,pi+1,high);
 }
}

void main(){
 int arr[20],n,i;
 clrscr();
 printf("Enter size of array:");
 scanf("%d",&n);
 printf("Enter array");
 for(i=0;i<n;++i)
  scanf("%d",&arr[i]);
 quicksort(arr,0,n-1);
 printf("\nSorted array is\n");
 for(i=0;i<n;++i)
  printf("%d ",arr[i]);
 getch();
}