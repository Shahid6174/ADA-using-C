#include <stdio.h>
int count = 0;

void towerOfHanoi(int n, char source, char dest, char temp)
{
    if (n == 1)
    {
        printf("Move the disc from %c to %c\n", source, dest);
        count++;
        return;
    }
    towerOfHanoi(n - 1, source, temp, dest);
    printf("Move the disc from %c to %c\n", source, dest);
    count++;
    towerOfHanoi(n - 1, temp, dest, source);
}

int main()
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    towerOfHanoi(n,'S','D','T');
    printf("The number of minimum disc movements are: %d\n", count);
    return 0;
}