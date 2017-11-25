
#include<stdio.h>
#include<conio.h>
void mergesort(int a[],int low,int mid,int high);
void partition(int a[],int low,int high);
void main()
{
int merge[50],i,n;
clrscr();
printf("\n Enter number of elements. \n");
scanf("%d",&n );
printf("\n Enter the elements: \n");
for(i=0;i<n;i++)
  scanf("%d",&merge[i]);
printf("\n Unsorted Array: \n");
for(i=0;i<n;i++)
  printf(" %d",merge[i]);
printf("\n");
partition(merge,0,n-1);
printf("\n Sorted array: \n");
for(i=0;i<n;i++)
  printf(" %d", merge[i]);
getch();
}
void partition(int a[],int low,int high)
{
 int mid;
 if(low<high)
   {
     mid=(low+high)/2;
     partition(a,low,mid);
     partition(a,mid+1,high);
     mergesort(a,low,mid,high);
   }
 }
 void mergesort(int a[], int low,int mid,int high)
 {
  int i,m,k,l,temp[50];
  l=low;
  i=low;
  m=mid+1;
  while((l<=mid) && (m<=high))
   { if(a[l] <= a[m])
	{ temp[i]=a[l];
	  l++;
	}
     else {
	   temp[i]=a[m];
	   m++;
	  }
     i++;
   }
 if(l>mid)
  { for(k=m;k<=high;k++)
      { temp[i]=a[k];
      i++;
      }
  }
 else {
       for(k=l;k<=mid;k++)
	 { temp[i]=a[k];
	   i++;
	 }
      }
 for(k=low;k<=high;k++)
     { a[k]=temp[k];
     }
 }