#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int res = 0;
    res = factorial(n);
    printf("The result is: %d\n", res);
    return 0;
}