#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a || b)
    {
        if (100 * a == 100 * b - a * b)
        {
            puts("equal");
        }
        else if ((double)a / (a + b - a * b / 100.0) > 0.5)
        {
            puts("SZL");
        }
        else
        {
            puts("XZM");
        }
    }
    else
    {
        puts("equal");
    }

    return 0;
}
