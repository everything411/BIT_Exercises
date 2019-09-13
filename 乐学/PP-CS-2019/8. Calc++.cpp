#include <iostream>
#include <cstring>
#define MOD 1000000
#define MAXN 100010
using namespace std;

char operand1[MAXN];
char operand2[MAXN];
char op;
long long ans[MAXN];
long long rev_op1[MAXN];
long long rev_op2[MAXN];
long long *dec_op1, *dec_op2;
int rev_op1_len, rev_op2_len;
int main(void)
{
    int flag = 0;
    int len1, len2;
    long long swap_tmp;
    while (~scanf("%s %c%s", operand1, &op, operand2))
    {
        len1 = strlen(operand1);
        len2 = strlen(operand2);
        memset(ans, 0, sizeof(ans));
        memset(rev_op1, 0, sizeof(rev_op1));
        memset(rev_op2, 0, sizeof(rev_op2));
        rev_op1_len = rev_op2_len = 0;
        for (int i = len1; i >= 0; i -= 6)
        {
            swap_tmp = 0;
            for (int j = max(0, i - 6); j < i; j++)
            {
                swap_tmp = swap_tmp * 10 + operand1[j] - '0';
            }
            rev_op1[rev_op1_len++] = swap_tmp;
        }
        for (int i = len2; i >= 0; i -= 6)
        {
            swap_tmp = 0;
            for (int j = max(0, i - 6); j < i; j++)
            {
                swap_tmp = swap_tmp * 10 + operand2[j] - '0';
            }
            rev_op2[rev_op2_len++] = swap_tmp;
        }
        switch (op)
        {
        case '+':
            for (int i = 0; i < max(rev_op1_len, rev_op2_len); i++)
            {
                ans[i] = rev_op1[i] + rev_op2[i];
            }
            for (int i = 0; i < max(rev_op1_len, rev_op2_len) + 2; i++)
            {
                if (ans[i] >= MOD)
                {
                    ans[i] -= MOD;
                    ans[i + 1]++;
                }
                // swap_tmp = ans[i] / MOD;
                // ans[i] %= MOD;
                // ans[i + 1] += swap_tmp;
            }
            break;
        case '-':
            if (len1 > len2 || (len1 == len2 && strcmp(operand1, operand2) >= 0))
            {
                dec_op1 = rev_op1;
                dec_op2 = rev_op2;
            }
            else
            {
                dec_op1 = rev_op2;
                dec_op2 = rev_op1;
                putchar('-');
            }

            for (int i = 0; i < max(rev_op1_len, rev_op2_len); i++)
            {
                ans[i] = dec_op1[i] - dec_op2[i];
            }
            for (int i = 0; i < rev_op1_len + rev_op2_len + 1; i++)
            {
                if (ans[i] < 0)
                {
                    ans[i] += MOD;
                    ans[i + 1]--;
                }
            }
            break;
        case '*':
            for (int i = 0; i < rev_op2_len; i++)
            {
                for (int j = 0; j < rev_op1_len; j++)
                {
                    ans[i + j] += rev_op2[i] * rev_op1[j];
                }
            }
            for (int i = 0; i < rev_op1_len + rev_op2_len + 1; i++)
            {
                swap_tmp = ans[i] / MOD;
                ans[i] %= MOD;
                ans[i + 1] += swap_tmp;
            }
            break;
        default:
            // go die!
            puts("go die!");
            goto case_fail;
            break;
        }
        flag = 0;
        for (int i = rev_op1_len + rev_op2_len; i >= 0; i--)
        {
            if (!flag && !ans[i])
            {
                if (!flag && i == 0)
                {
                    putchar('0');
                }
                continue;
            }
            if (!flag)
            {
                printf("%lld", ans[i]);
                flag = 1;
            }
            else
            {
                printf("%06lld", ans[i]);
            }
        }
        putchar('\n');
    case_fail:;
    }
    return 0;
}