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

void linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i]==key)
        {
            printf("Key found at %d location\n", i+1);
            return;
        }
    }
    printf("Key not found\n");
    return;
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
    printArray(arr,n);
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    start = clock();
    linearSearch(arr,n,key);
    end = clock();

    cpu_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time taken is: %lf\n", cpu_time);
}