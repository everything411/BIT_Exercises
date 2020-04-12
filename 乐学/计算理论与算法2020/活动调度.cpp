#include <iostream>
#include <algorithm>
#define MAXN 1000010
using namespace std;
int s[MAXN];
int e[MAXN];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", s + i, e + i);
    }
    sort(s, s + n);
    sort(e, e + n);
    int ans = 0;
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < n)
    {
        if (s[i] < e[j])
        {
            cnt++;
            i++;
        }
        else if (s[i] > e[j])
        {
            cnt--;
            j++;
        }
        else
        {
            i++;
            j++;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);

    return 0;
}
