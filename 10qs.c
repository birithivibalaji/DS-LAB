#include<stdio.h>  
voidswap(int* a, int* b) { 
int temp = *a; 
*a = *b; 
*b = temp; 
} 
intpartition(int arr[], int low, int high) { 
int pivot = arr[high];  
int i = low - 1;  
for (int j = low; j < high; j++) { 
if (arr[j] < pivot) { 
i++; 
swap(&arr[i], &arr[j]); 
} 
}  
swap(&arr[i + 1], &arr[high]); 
return i + 1; 
} 
voidquickSort(int arr[], int low, int high) { 
if (low < high) { 
int pi = intpartition(arr, low, high);  
voidquickSort(arr, low, pi - 1); 
voidquickSort(arr, pi + 1, high); 
} 
} 
voidprintArray(int arr[], int size) { 
for (int i = 0; i < size; i++) 
printf("%d ", arr[i]); 
printf("\n"); 
}  
intmain() { 
int arr[] = {12, 7, 11, 13, 5, 6}; 
int n = sizeof(arr) / sizeof(arr[0]); 
printf("Original array:\n"); 
voidprintArray(arr, n); 
quickSort(arr, 0, n - 1); 
printf("Sorted array:\n"); 
printArray(arr, n); 
return 0; 
}

OUTPUT:
Original array:
127111356
Sorted array:
567111213
