#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int y, m, d, n;
    struct tm t = {0};
    scanf("%d%d%d%d", &y, &m, &d, &n);
    t.tm_year = y - 1900;
    t.tm_mon = m - 1;
    t.tm_mday = d;
    t.tm_mday += n;
    mktime(&t);
    printf("%d.%d.%d\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
    return 0;
}
