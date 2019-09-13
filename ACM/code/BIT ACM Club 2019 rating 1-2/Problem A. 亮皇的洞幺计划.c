#include <stdio.h>
#include <string.h>
extern char *gets(char *);
void not_op(char *str)
{
    while (*str == '0')
        *str++ = '1';
}
char str[400000];
int main(int argc, char const *argv[])
{
    long long len, rev_cost, not_cost;
    char *pos = str;
    long long ans1 = 0;
    long long ans2 = 0;
    long long count = 0;
    scanf("%lld%lld%lld%s", &len, &rev_cost, &not_cost, str);
    while (pos && (pos = strchr(pos, '0')))
    {
        not_op(pos);
        count++;
    }
    ans1 = not_cost * count;
    ans2 = rev_cost * count;
    if (count)
        ans2 += not_cost - rev_cost;

    printf("%lld\n", ans1 > ans2 ? ans2 : ans1);
    return 0;
}