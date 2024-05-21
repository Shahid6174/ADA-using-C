#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int arr[100000];
clock_t start, end;
double cpu_time;

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void min_max(int low, int high, int *max, int *min)
{
    if(low==high)
    {
        *min = *max = arr[low];
        return;
    }
    else if(low==high-1)
    {
        if(arr[low]<arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }
    else
    {   
        int max1, min1;
        int mid = (low+high)/2;
        min_max(low,mid,max,min);
        min_max(mid+1,high,&max1,&min1);
        if(*max < max1)
        {
            *max = max1;
        }
        if(*min > min1)
        {
            *min = min1;
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    for(int i = 0; i<n; i++)
    {
        arr[i] = rand()%9001+1000;
    }

    printf("The array is: \n");
    printArray(arr,n);

    int max = -1, min =-1;

    start = clock();
    min_max(0,n-1,&max,&min);
    end = clock();

    printf("The minimum element is: %d and the maximum element is: %d \n", min, max);
    cpu_time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("CPU Time take is: %lf \n",cpu_time);
    return 0;
}