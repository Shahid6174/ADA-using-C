#include <stdio.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}
int knapsack(int capacity, int wt[], int val[], int n)
{
    int i, w;
    int dp[n+1][capacity+1];
    for(i=0; i<=n; i++)
    {
        for(w=0; w<=capacity; w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(w - wt[i-1] >= 0)
            {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter the value/profit and weight for each item:\n");
    int i;
    for(i=0; i<n; i++)
    {
        printf("Item %d value: ", i+1);
        scanf("%d", &val[i]);
        printf("Item %d weight: ", i+1);
        scanf("%d", &wt[i]);
    }
    printf("Enter the capacity of the bag: ");
    scanf("%d", &capacity);

    printf("Maximum value that can be obtained is %d\n", knapsack(capacity, wt, val, n));

}