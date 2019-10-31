#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int a, b;
    int ans = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (i % 7 == 0)
        {
            ans++;
        }
        else
        {
            int c = abs(i);
            while (c > 0)
            {
                if (c % 10 == 7)
                {
                    ans++;
                    break;
                }
                c /= 10;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
