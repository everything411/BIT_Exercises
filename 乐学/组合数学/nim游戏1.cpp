#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int stonenum[1010];
    int x;
    int ans;

    while (~scanf("%d", &n) && n)
    {
        x = 0;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &stonenum[i]);
            x ^= stonenum[i];
        }
        for (int i = 0; i < n; i++)
        {
            if ((x ^ stonenum[i]) < stonenum[i])
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
