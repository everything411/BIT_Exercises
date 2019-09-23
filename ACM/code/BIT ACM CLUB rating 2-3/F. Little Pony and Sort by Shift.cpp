#include <iostream>
using namespace std;
int buf[100010];
int n;
int check(int pos)
{
    if (pos == -1)
    {
        return 0;
    }
    else if (buf[0] < buf[n - 1])
    {
        return -1;
    }
    else
    {
        return n - pos;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    scanf("%d", buf);
    int cnt = 0;
    int pos = -1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", buf + i);
        if (buf[i] < buf[i - 1])
        {
            if (pos == -1)
            {
                pos = i;
            }

            cnt++;
        }
    }
    int ans;
    if (cnt > 1)
    {
        puts("-1");
    }
    else
    {
        printf("%d\n", check(pos));
    }
    return 0;
}
