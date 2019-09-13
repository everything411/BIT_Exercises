#include <stdio.h>
int main(int argc, char const *argv[])
{
    int start, end;
    int sum = 0;
    scanf("%d%d", &start, &end);
    for (int i = start; i <= end; i++)
    {
        sum += i;
    }
    printf("The sum from %d to %d is %d.\n", start, end, sum);
    return 0;
}
