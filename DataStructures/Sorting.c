#include<stdio.h>
#define max 50
void quicksort(int[],int,int);
int partition(int[],int,int);
void mergesort(int[],int,int);
void Merge(int[],int,int,int);
void insertion(int[],int);
int main() 
{ 
 int A[max];
 int i,n,ch,l,h;
 printf("Enter number of elements of array\n");
 scanf("%d",&n);
 
 printf("Enter the elements\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&A[i]);
 }
 l=0,h=n-1;
while(1)
{
 printf("\n1:Quick Sort\n2:Merge Sort\n3: Insertion Sort\n4:Exit");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
  quicksort(A,l,h);
  break;
  
  case 2:
  mergesort(A,l,h);
  break;
  
  case 3:
  insertion(A,n);
  break;
  
  case 4:
   exit(0);
 }
}
 printf("The sorted array is\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t",A[i]);
 }
printf("\n");
}

void quicksort(int A[],int l,int h)
{
 if(l<h)
 {
  int j=partition(A,l,h);
  quicksort(A,l,j-1);
  quicksort(A,j+1,h);
 }
}

int partition(int A[],int l,int h)
{
 int pivot,i,j,temp;
 pivot=A[l];
 i=l-1,j=h+1;
 while(i<j)
 {
  do{
     i++;
  }while(A[i]<pivot&&i<j);
 // printf("%d",A[i]);
  do{
     j--;
  }while(A[j]>pivot);
  //printf("%d",A[j]);
  if(i<j)
  {
 // printf("A");
   temp=A[i];
   A[i]=A[j];
   A[j]=temp;
  }
 }
// printf("%d\n",A[l]);
if(A[j]<=pivot)
{
 temp=A[l];
 A[l]=A[j];
 A[j]=temp;
}
// printf("%d\n",A[l]);
 //printf("%d\n",A[j]);
 return j;
}

void mergesort(int A[],int l,int h)
{
 if(l<h)
 {
  int mid=(l+h)/2;
  mergesort(A,l,mid);
  mergesort(A,mid+1,h);
  Merge(A,l,mid,h);
 }
}

void Merge(int A[],int l,int mid,int h)
{
 int n1,n2,i,j,k;
 n1=mid-l+1;
 n2=h-mid;
 int Left[n1],Right[n2];
 for(k=0;k<n1;k++)
 {
  Left[k]=A[l+k];
 }
 for(k=0;k<n2;k++)
 {
  Right[k]=A[mid+1+k];
 }
 i=0,j=0,k=l;
 while(i<n1&&j<n2)
 {
  if(Left[i]<=Right[j])
  {
   A[k++]=Left[i++];
  }
  else{
  A[k++]=Right[j++];
  }
 }
 while(i<n1)
 {
  A[k++]=Left[i++];
 }
 while(j<n2)
 {
  A[k++]=Right[j++];
 }
}

void insertion(int A[],int n)
{
 int key,i,j;
 for(i=0;i<n;i++)
 {
  key=A[i];
  j=i-1;
  while(A[j]>key && j>=0)
  {
   A[j+1]=A[j];
   j--;
  }
  A[j+1]=key;
 }
} 
