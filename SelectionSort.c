//Lab Program

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t start, end;
int arr[100000];
double cpu_time;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    int min, i, j;
    for(i=0; i<n-1; i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
        if(arr[min]>arr[j])
        {
            min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

int main()
{
    int n,i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        arr[i] = rand()%9001+1000;
    }

    printf("The unsorted array is: ");
    printArray(arr,n);

    start = clock();
    selectionSort(arr,n);
    end = clock();

    cpu_time = (double)(end-start)/CLOCKS_PER_SEC;

    printf("The sorted array is: ");
    printArray(arr,n);

    printf("The time taken is: %lf\n", cpu_time);
}