#include<stdio.h>
void QuickSort(int x[100],int low,int high){
	if(low<high){
		int pivot=low;
		int i=low;
		int j=high;
		int t;
		while(i<j){
			while(x[i]<=x[pivot]&&i<high)
			i++;
			while(x[j]>x[pivot])
			j--;
			if(i<j){
				t=x[i];
				x[i]=x[j];
				x[j]=t;
			}
		}
		t=x[pivot];
		x[pivot]=x[j];
		x[j]=t;
		QuickSort(x,low,j-1);
		QuickSort(x,j+1,high);
	}
}
void main(){
	int a[100];
	int n,i;
	printf("Enter the array size: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	QuickSort(a,0,n-1);
	printf("Sorted array: ");
	for(i=0;i<n;i++)
	printf("%d \n",a[i]);
}
