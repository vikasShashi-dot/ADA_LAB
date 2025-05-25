#include <stdio.h>
#include <stdlib.h>
#include <time.h>

swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
   
    if (left < n && arr[left] > arr[largest])
        largest = left;
   
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); 
    }
}

void heapSort(int arr[], int n)
{
 
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        
        swap(&arr[0], &arr[i]);
        
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{


    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    clock_t start = clock();
 
    heapSort(arr, n);
 
    clock_t end = clock();

    printf("Sorted array: ");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %f seconds\n", time_taken);
    return 0;
}