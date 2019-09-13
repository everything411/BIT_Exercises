#include <stdio.h>
#define MAXN 100010
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define LEFT 0
#define RIGHT 1
int str_val[MAXN][2];
int lr_cnt[2][MAXN];
int left, right;
int maxleft, maxright;
int minmax = MAXN;
int legal_cnt;
// stack
char str[MAXN];
int pos;
inline void pop(void)
{
    --pos;
}
inline char top(void)
{
    return pos - 1 >= 0 ? str[pos - 1] : 0;
}
inline void push(char ch)
{
    str[pos++] = ch;
}

void getcnt(int index)
{
    for (int i = 0; i < pos; i++)
    {
        if (str[i] == '(')
        {
            str_val[index][LEFT]++;
        }
        else
        {
            str_val[index][RIGHT]++;
        }
    }
    maxleft = max(maxleft, str_val[index][LEFT]);
    maxright = max(maxright, str_val[index][RIGHT]);
    if (str_val[index][LEFT] > 0 && str_val[index][RIGHT] > 0)
    {
        ; // pass
    }
    else if (str_val[index][LEFT] > 0)
    {
        lr_cnt[LEFT][str_val[index][LEFT]]++;
    }
    else if (str_val[index][RIGHT] > 0)
    {
        lr_cnt[RIGHT][str_val[index][RIGHT]]++;
    }
    else
    {
        legal_cnt++;
    }
}
int main(void)
{
    int n;
    char ch;
    int ans = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        pos = 0;
        while ((ch = getchar()) != '\n')
        {
            if (ch == '(')
            {
                push(ch);
            }
            else // ')'
            {
                if (top() == '(')
                {
                    pop();
                }
                else
                {
                    push(ch);
                }
            }
        }
        getcnt(i);
    }
    minmax = min(maxleft, maxright);
    ans = legal_cnt / 2;
    for (int i = 0; i <= minmax; i++)
    {
        ans += min(lr_cnt[LEFT][i], lr_cnt[RIGHT][i]);
    }
    printf("%d\n", ans);
    return 0;
}
