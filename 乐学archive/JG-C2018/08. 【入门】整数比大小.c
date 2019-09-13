#include <stdio.h>
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("min=%d\n", a > b ? b : a);
    return 0;
}