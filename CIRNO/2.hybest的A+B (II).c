#include <stdio.h>
int main()
{
    int len;
    int a, b;
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}