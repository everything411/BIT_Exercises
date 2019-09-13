#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long to_ll(char *str, int len)
{
    long long ret = 0;
    for (int i = 0; i < len; i++)
    {
        ret = ret * 10 + str[i] - '0';
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    int T;
    long long max_val;
    long long val_buf[5];
    char str[30];
    int len;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        max_val = -0x7F66CCFF;
        scanf("%s", str);
        len = strlen(str);
        if (len == 5)
        {
            for (int i = 0; i < 5; i++)
                val_buf[i] = to_ll(str + i, 1);
            max_val = val_buf[0] + val_buf[1] - val_buf[2] * val_buf[3] / val_buf[4];
        }
        else
        {
            // len of e == 1
            val_buf[0] = to_ll(str, len - 4);
            for (int i = 1; i < 5; i++)
                val_buf[i] = to_ll(str + i + len - 5, 1);
            max_val = max(max_val, val_buf[0] + val_buf[1] - val_buf[2] * val_buf[3] / val_buf[4]);
            val_buf[0] = to_ll(str, 1);
            val_buf[1] = to_ll(str + 1, len - 4);
            for (int i = 2; i < 5; i++)
                val_buf[i] = to_ll(str + i + len - 5, 1);
            max_val = max(max_val, val_buf[0] + val_buf[1] - val_buf[2] * val_buf[3] / val_buf[4]);
            // len of e == 2
            val_buf[0] = to_ll(str, len - 5);
            for (int i = 1; i < 4; i++)
                val_buf[i] = to_ll(str + i + len - 6, 1);
            val_buf[4] = to_ll(str + len - 2, 2);
            max_val = max(max_val, val_buf[0] + val_buf[1] - val_buf[2] * val_buf[3] / val_buf[4]);
            val_buf[0] = to_ll(str, 1);
            val_buf[1] = to_ll(str + 1, len - 5);
            for (int i = 2; i < 4; i++)
                val_buf[i] = to_ll(str + i + len - 6, 1);
            val_buf[4] = to_ll(str + len - 2, 2);
            max_val = max(max_val, val_buf[0] + val_buf[1] - val_buf[2] * val_buf[3] / val_buf[4]);
        }
        printf("Case #%d: %lld\n", i + 1, max_val);
    }
    return 0;
}
