#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int m[20][20];
int t[20];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
        t[i] = i;
    }
    int ans = INT_MAX;
    int c;
    do
    {
        c = 0;
        for (int i = 0; i < n; i++)
        {
            c += m[i][t[i]];
        }
        ans = min(ans, c);
    } while (next_permutation(t, t + n));
    printf("%d\n", ans);
    return 0;
}
