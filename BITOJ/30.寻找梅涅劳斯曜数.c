#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (!(i % j))
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
