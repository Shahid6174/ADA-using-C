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

void binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == key)
        {
            printf("Key found at %d location.\n", mid+1);
            return;
        }
        else if(key > arr[mid])
        {
            low=mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    printf("Key not found.\n");
}

void merge(int arr[], int left[], int right[], int p, int q)
{
    int i=0, j=0,k=0;
    while(i<p && j<q)
    {
        if(left[i]<right[j])
        {
            arr[k] = left[i];
            i += 1;
        }
        else
        {
            arr[k] = right[j];
            j += 1;
        }
        k+=1;
    }
    while(i<p)
    {
        arr[k] = left[i];
        i += 1;
        k+= 1;
    }
    while(j<q)
    {
        arr[k] = right[j];
        j +=1 ;
        k += 1;
    }

}
void mergeSort(int arr[], int n)
{
    if(n<=1)
    {
        return;
    }
    int left[n/2];
    int right[n-n/2];
    for(int i=0;i<n/2;i++)
    {
        left[i] = arr[i];
    }
    for(int j=0;j<n-n/2;j++)
    {
        right[j] = arr[j+n/2];
    }
    mergeSort(left, n/2);
    mergeSort(right, n-n/2);
    merge(arr,left,right,n/2, n-n/2);
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
    mergeSort(arr,n);
    printf("The sorted array is: ");
    printArray(arr,n);
    int key;

    printf("Enter the key: ");
    scanf("%d", &key);

    start = clock();
    binarySearch(arr,n,key);
    end = clock();

    cpu_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time taken is: %lf\n", cpu_time);
}