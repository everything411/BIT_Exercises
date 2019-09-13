#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MOD 10
#define MAXN 15000
const int calc_table[] = {0, 1, 2, 3, 4, 5, 6, 7, 7, 8};
char buf[2][MAXN];
int num_buf[MAXN];
int no7cnt[MAXN];
int big_ans[MAXN];
int small_ans[MAXN];
// a(arg1) + b(arg2)
void add(int *a, int *const a_len, const int b)
{
    assert(b <= 10 && b >= 0);
    int len = *a_len;
    a[0] += b;
    for (int i = 0; i <= len; i++)
    {
        if (a[i] >= MOD)
        {
            a[i] -= MOD;
            a[i + 1]++;
        }
    }
    *a_len += (a[len] > 0);
}
// a(arg1) - b(arg2)
// a >= b
void sub(int *a, int *a_len, const int *b, const int *const b_len)
{
    for (int i = 0; i < *b_len; i++)
    {
        a[i] -= b[i];
    }
    for (int i = 0; i <= *a_len; i++)
    {
        if (a[i] < 0)
        {
            a[i] += MOD;
            a[i + 1]--;
        }
    }
    for (int i = *a_len - 1; i >= 0; i--)
    {
        if (a[i] != 0 || i == 0)
        {
            *a_len = i + 1;
            return;
        }
    }
    return; // never happen
}
// a(arg1) * b(arg2)
void mul(int *a, int *a_len, const int b)
{
    int len = *a_len;
    int swap_tmp;
    for (int i = 0; i < len; i++)
    {
        a[i] *= b;
    }
    for (int i = 0; i < len + 100; i++)
    {
        swap_tmp = a[i] / MOD;
        a[i] %= MOD;
        a[i + 1] += swap_tmp;
    }
    for (int i = len + 100; i >= 0; i--)
    {
        if (a[i] != 0 || i == 0)
        {
            *a_len = i + 1;
            return;
        }
    }
    return; // never happen
}
int rev_char2ll(int *dst, const char *src)
{
    int len = strlen(src);
    for (int i = len - 1; i >= 0; i--)
    {
        dst[len - i - 1] = src[i] - '0';
    }
    return len;
}
void num_print(int *num, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d", num[i]);
    }
    putchar('\n');
}
int main(int argc, char const *argv[])
{
    int t;
    char *big_num, *small_num;
    int big_cnt_len, small_cnt_len;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int has_seven;
        int cnt_len;
        int num_curr;
        memset(buf, 0, sizeof(buf));
        memset(big_ans, 0, sizeof(big_ans));
        memset(small_ans, 0, sizeof(small_ans));
        scanf("%s%s", buf[0], buf[1]);
        small_num = buf[0];
        big_num = buf[1];
        int small_len = strlen(small_num);
        int big_len = strlen(big_num);
        if (!(big_len > small_len || (big_len == small_len && strcmp(big_num, small_num) >= 0)))
        {
            int tmp1;
            char *tmp2;
            tmp1 = small_len, tmp2 = small_num;
            small_len = big_len, small_num = big_num;
            big_len = tmp1, big_num = tmp2;
        }
        memset(num_buf, 0, sizeof(num_buf));
        memset(no7cnt, 0, sizeof(no7cnt));
        has_seven = 0;
        cnt_len = 1;
        rev_char2ll(num_buf, big_num);
        for (int i = 0; i < big_len; i++)
        {
            num_curr = big_num[i] - '0';
            if (i != 0)
            {
                mul(no7cnt, &cnt_len, 9);
            }
            if (!has_seven)
            {
                add(no7cnt, &cnt_len, calc_table[num_curr]);
            }
            if (num_curr == 7)
            {
                has_seven = 1;
            }
        }
        sub(num_buf, &big_len, no7cnt, &cnt_len);
        if (strchr(big_num, '7'))
        {
            add(num_buf, &big_len, 1);
        }
        big_cnt_len = big_len;
        memcpy(big_ans, num_buf, sizeof(big_ans));

        memset(num_buf, 0, sizeof(num_buf));
        memset(no7cnt, 0, sizeof(no7cnt));
        has_seven = 0;
        cnt_len = 1;
        rev_char2ll(num_buf, small_num);
        for (int i = 0; i < small_len; i++)
        {
            num_curr = small_num[i] - '0';
            if (i != 0)
            {
                mul(no7cnt, &cnt_len, 9);
            }
            if (!has_seven)
            {
                add(no7cnt, &cnt_len, calc_table[num_curr]);
            }
            if (num_curr == 7)
            {
                has_seven = 1;
            }
        }
        sub(num_buf, &small_len, no7cnt, &cnt_len);
        // if (strchr(small_num, '7'))
        // {
        //     add(num_buf, &small_len, 1);
        // }
        small_cnt_len = small_len;
        memcpy(small_ans, num_buf, sizeof(small_ans));
        sub(big_ans, &big_cnt_len, small_ans, &small_cnt_len);
        num_print(big_ans, big_cnt_len);
    }
    return 0;
}
