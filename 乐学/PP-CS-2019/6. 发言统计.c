#include <stdio.h>
#include <string.h>
#define P 51787
extern char *gets(char *);
char str[100];
long long hash[5000];
int len;
unsigned long long get_hash(char *str, int len)
{
    unsigned long long ret = str[0];
    for (int i = 1; i < len; i++)
    {
        ret = ret * P + str[i];
    }
    return ret;
}
unsigned long long find_hash(unsigned long long h, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        if (h == hash[i])
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int n;
    int cnt = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(str);
        len = strlen(str);
        if (len > 10)
        {
            hash[cnt] = get_hash(str, len);
            if (!find_hash(hash[cnt], cnt))
            {
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}