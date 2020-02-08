#include <iostream>
using namespace std;
int vis[128];
char mp[128];
int in[26], out[26];
int main()
{
    int cnt = 0;
    char ch;
    bool first;
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            vis[ch] = cnt;
            mp[cnt++] = ch;
        }
    }
    ch = getchar();
    first = true;
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            if (first)
            {
                out[vis[ch]]++;
                first = false;
            }
            else
            {
                in[vis[ch]]++;
                first = true;
            }
        }
    }

    first = true;
    for (int i = 0; i < cnt; i++)
    {
        if (!in[i])
        {
            if (first)
            {
                first = false;
                printf("%c", mp[i]);
            }
            else
            {
                printf(",%c", mp[i]);
            }
        }
    }
    putchar('\n');
    first = true;
    for (int i = 0; i < cnt; i++)
    {
        if (!out[i])
        {
            if (first)
            {
                first = false;
                printf("%c", mp[i]);
            }
            else
            {
                printf(",%c", mp[i]);
            }
        }
    }
    putchar('\n');
    return 0;
}
