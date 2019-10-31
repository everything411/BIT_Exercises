#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, m, x;
    int pos = 0;
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; n > 0; i++)
    {
        pos += n--;
        if (pos >= x)
        {
            printf("青蛙能爬出井，且第 %d 天爬出井。\n", i + 1);
            return 0;
        }
        pos -= m;
        if (pos <= 0)
        {
            break;
        }
    }
    puts("青蛙不能爬出井。");
    return 0;
}
