#include <stdio.h>

#define MAX 10

void main()
{
    int i, j, arr[MAX][MAX], n, queue[MAX], flag[MAX];
    int m = 0, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        flag[i] = 0;
        queue[i] = 0;
    }
    
    printf("Enter the adjacency matrix: \n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j])
            {
                flag[j]++;
            }
        }
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            if(flag[i] == 0)
            {
                flag[i] = -1; 
                queue[++m] = i; 
                for(j = 1; j <= n; j++)
                {
                    if(arr[i][j] == 1)
                    {
                        flag[j]--;
                    }
                }
                break;
            }
        }
    }

    if(m == n)
    {
        printf("The topological order is: \n");
        for(i = 1; i <= n; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No topological order possible as it is not a DAG.\n");
    }
}
