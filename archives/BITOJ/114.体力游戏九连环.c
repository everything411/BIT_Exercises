#include <stdio.h>
long long g_counter;
void up(int n);
void down(int n);

int main(int argc, char const *argv[])
{
    int count = 1;
    int n;
    while (~scanf("%d", &n))
    {
        g_counter = 0;
        printf("Case %d:\n", count++);
        down(n);
        printf("step:%lld\n", g_counter);
    }
    return 0;
}
void down(int n)
{
    if (n > 2)
        down(n - 2);
    printf("%d loop down\n", n);
    g_counter++;
    if (n > 2)
        up(n - 2);
    if (n > 1)
        down(n - 1);
}

void up(int n)
{
    if (n > 1)
        up(n - 1);
    if (n > 2)
        down(n - 2);
    printf("%d loop up\n", n);
    g_counter++;
    if (n > 2)
        up(n - 2);
}