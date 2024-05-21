#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t start, end;
int arr[100000];
double cpu_time;

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i<n; i++)
    {
        int hole = i;
        int val = arr[i];
        while(hole>0 && arr[hole-1]>val)
        {
            arr[hole] = arr[hole-1];
            hole -= 1;
        }
        arr[hole] = val;
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

    printf("The unsorted array is: \n");
    printArray(arr,n);

    start = clock();
    insertionSort(arr,n);
    end = clock();

    cpu_time = (double)(end-start)/CLOCKS_PER_SEC;

    printf("The sorted array is: \n");
    printArray(arr,n);

    printf("The time taken is: %lf\n", cpu_time);
}