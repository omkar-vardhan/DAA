#include<stdio.h>
void mergeSort(int [],int,int);
void merge(int [],int,int,int);
void mergeSort(int a[],int beg,int end){
int mid;
if(beg<end){
	mid=(beg+end)/2;
	mergeSort(a,beg,mid);
	mergeSort(a,mid+1,end);
	merge(a,beg,mid,end);
}	

}
void merge(int a[],int beg,int mid,int end){
	int i=beg,j=mid+1,index=beg,k;
	int temp[20];
	while((i<=mid)&&(j<=end)){
		if(a[i]<a[j]){
			temp[index]=a[i];
			i++;
		}
		else{
			temp[index]=a[j];
			j++;
		}
		index++;
	}
	if(i>mid){
		while(j<=end){
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	else{
		while(i<=mid){
			temp[index]=a[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
	a[k]=temp[k];
}
 void main()
    {
	int a[100],n,i;        
        printf("Enter the array size:");
        scanf("%d",&n);
        printf("Enter the array elements:");
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        mergeSort(a, 0, n-1);
        printf("Sorted array:");
        for (i = 0; i < n; i++)
        printf("%d \t",a[i]);
        getch();
     }

