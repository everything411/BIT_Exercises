#include <iostream>
using namespace std;
bool check(int passhash)
{
    int cnt;
    scanf("%d", &cnt);
    char str[100][3];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%s", str[i]);
        if ((str[i][0] << 8) + str[i][1] == passhash)
            return true;
    }

    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
            if ((str[i][1] << 8) + str[j][0] == passhash)
                return true;
    return false;
}
int main(void)
{
    char passwd[3];
    scanf("%s", passwd);
    if (check((passwd[0] << 8) + passwd[1]))
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}