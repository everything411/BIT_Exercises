/**
 * 作者：babydragon
 * 链接：https://www.zhihu.com/question/308096400/answer/640448496
 * 来源：知乎
 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <stdbool.h>
int num[10] = {0, 4, 4, 4, 4, 4, 4};

bool dfs(int tot, int turn, int player)
{
    if (tot == 31 && player == 0)
    {
        return false;
    }
    if (player == 1 && tot == 31)
    {
        return true;
    }
    int cnt = 0;
    int in = 0;
    int cntprev = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (num[i] && tot + i <= 31)
        {
            in++;
            num[i]--;
            if (dfs(tot + i, turn + 1, 1 - player))
            {
                cnt++;
            }
            num[i]++;
        }
        if (turn == 0 && cnt > cntprev)
        {
            printf("%d\n", i);
        }
        cntprev = cnt;
    }

    if (in == 0 && player == 0)
    {
        return false;
    }
    else if (in == 0 && player == 1)
    {
        return true;
    }
    if (player == 0 && cnt >= 1)
    {
        return true;
    }
    else if (player == 0)
    {
        return false;
    }
    else if (player == 1 && cnt == in)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    dfs(0, 0, 0);
    return 0;
}