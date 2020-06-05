#include <iostream>
#include <cstring>
using namespace std;
char str[1010];
char ans[1010];
int numcnt[10];
int sum;
bool try_delete(int i, int j, int k)
{
    if (numcnt[i] + numcnt[j] + numcnt[k] == 0)
    {
        return false;
    }
    if (numcnt[i])
    {
        numcnt[i]--;
        sum -= i;
    }
    else if (numcnt[j])
    {
        numcnt[j]--;
        sum -= j;
    }
    else if (numcnt[k])
    {
        numcnt[k]--;
        sum -= k;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%s", str))
    {
        memset(ans, 0, sizeof(ans));
        memset(numcnt, 0, sizeof(numcnt));
        int len = strlen(str);
        sum = 0;
        char *ans_pos = ans + len - 1;
        for (int i = 0; i < len; i++)
        {
            numcnt[str[i] - '0']++;
        }
        for (int i = 0; i < 10; i++)
        {
            sum += i * numcnt[i];
        }
        if (numcnt[0] == 0 && numcnt[5] == 0)
        {
            goto impossible;
        }
        else if (numcnt[0] != 0)
        {
            *ans_pos-- = '0';
            numcnt[0]--;
        }
        else if (numcnt[5] != 0)
        {
            *ans_pos-- = '5';
            numcnt[5]--;
        }
        switch (sum % 3)
        {
        case 1:
            if (!(try_delete(1, 4, 7) || (try_delete(2, 5, 8) && try_delete(2, 5, 8))))
            {
                goto impossible;
            }
            break;
        case 2:
            if (!(try_delete(2, 5, 8) || (try_delete(1, 4, 7) && try_delete(1, 4, 7))))
            {
                goto impossible;
            }
            break;
        default:
            break;
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < numcnt[i]; j++)
            {
                *ans_pos-- = i + '0';
            }
        }
        if (sum == 0)
        {
            puts("0");
        }
        else
        {
            puts(ans_pos + 1);
        }
        while (0)
        {
        impossible:
            puts("impossible");
            break;
        }
    }

    return 0;
}
