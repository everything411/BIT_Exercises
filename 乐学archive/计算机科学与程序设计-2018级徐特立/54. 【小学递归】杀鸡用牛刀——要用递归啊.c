#include <stdio.h>
int sum(int, int);
int main(int argc, char const *argv[])
{
    int min, max;
    scanf("%d%d", &min, &max);
    printf("The sum from %d to %d is %d.\n", min, max, sum(min, max));
    return 0;
}
int sum(int min, int max)
{
    if (min < max)
        return sum(min, max - 1) + max;
    else
        return min;
}