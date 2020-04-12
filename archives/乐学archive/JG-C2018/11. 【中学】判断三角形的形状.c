#include <stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b == c)
        puts("equilateral triangle.");
    else if (!(a + b > c && a + c > b && b + c > a))
        puts("non-triangle.");
    else if (a == b || b == c || c == a)
        puts("isoceles triangle.");
    else
        puts("triangle.");
    return 0;
}