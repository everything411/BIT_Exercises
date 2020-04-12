#include <stdio.h>
int main(void)
{
    int a;
    scanf("%d", &a);
    printf("%d %s", a, (a % 100 ? a % 4 : a % 400) ? "is not a leap year.\n" : "is a leap year.\n");
    return 0;
}