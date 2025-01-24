#include <stdio.h> 
 

int binarySearchRecursive(int arr[], int low, int high, int key) {     if (low > high) { 
        return -1;  
    } 
 
    int mid = low + (high - low) / 2; 
 
     
    if (arr[mid] == key) { 
        return mid; 
    } 
 
        if (arr[mid] > key) { 
        return binarySearchRecursive(arr, low, mid - 1, key); 
    } 
 
       return binarySearchRecursive(arr, mid + 1, high, key); 
} 
 
int main() { 
    int n, key, result; 
 
     
    printf("Enter the number of elements in the array: ");     scanf("%d", &n); 
 
    int arr[n]; 
 
   
    printf("Enter %d sorted elements:\n", n);     
	for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
         printf("Enter the target element to search: ");    
		  scanf("%d", &key); 
 
     
    result = binarySearchRecursive(arr, 0, n - 1, key); 
 
         if (result != -1) { 
        printf("Element found at index %d (0-based index).\n", result);     } else { 
        printf("Element not found in the array.\n"); 
    } 
 
    return 0; 
} 
 

