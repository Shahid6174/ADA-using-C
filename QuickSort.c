#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t start, end;
double cpu_time;
int arr[100000];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start, j = end;

    while (i < j)
    {
        while (arr[i] <= pivot && i < end)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[start], &arr[j]);
    return j;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 9001 + 1000;
    }
    printf("The unsorted array is: \n");
    printArray(arr, n);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("The sorted array is: \n");
    printArray(arr, n);

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("The time taken to sort the array is %f seconds.\n", cpu_time);

    return 0;
}
