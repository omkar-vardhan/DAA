#include<stdio.h>
int binarySearch(int arr[],int n,int key){
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low/2);
		if(arr[mid]==key){
			return mid;
		}
		if(arr[mid]>key){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	    return -1; 
} 
 
int main() {     
int n, key, result,i; 
    printf("Enter the number of elements in the array: ");    
	scanf("%d", &n); 
    int arr[n]; 
    printf("Enter %d sorted elements:\n", n);     
	for ( i = 0; i < n; i++) {         
	scanf("%d", &arr[i]); 
    } 
 
    if (result != -1) { 
        printf("Element found at index %d (0-based index).\n", result);    
		 } else { 
        printf("Element not found in the array.\n"); 
    } 
 
    return 0; 
} 


