#include <stdio.h>
int f(int x);
int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", f(x));
    return 0;
}
int f(int x)
{
    switch (x)
    {
    case 1:
        return 5;
    case 2:
        return 1;
    default:
        return f(x - 1) + f(x - 2) + 3;
    }
}