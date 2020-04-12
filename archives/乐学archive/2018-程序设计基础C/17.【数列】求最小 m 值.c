#include<stdio.h>
int main(int argc, char const *argv[])
{
    int i, n, sum = 0;
    scanf("%d", &n);
    for(i = 1; sum < n; i++)
        sum += i;
    printf("%d\n", --i);
    return 0;
}
