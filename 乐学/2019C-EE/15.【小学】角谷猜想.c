#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 20; i++)
    {
        if (n & 1)
        {
            printf("%d*3+1=%d\n", n, n * 3 + 1);
            n = n * 3 + 1;
        }
        else
        {
            printf("%d/2=%d\n", n, n / 2);
            n /= 2;
        }
        if (n == 1)
        {
            break;
        }
    }

    return 0;
}
