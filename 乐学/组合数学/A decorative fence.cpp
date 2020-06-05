#include <iostream>
#include <cstring>
#define LOW 0
#define HIGH 1
using namespace std;
long long f[30][30][2];
int res[30];
int vis[30];
void calc_ans()
{
    f[1][1][LOW] = 1;
    f[1][1][HIGH] = 1;
    for (int n = 2; n < 30; n++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int i = 1; i <= a - 1; i++)
            {
                f[a][n][LOW] += f[i][n - 1][HIGH];
            }
            for (int i = a; i <= n - 1; i++)
            {
                f[a][n][HIGH] += f[i][n - 1][LOW];
            }
        }
    }
}
void Print(int n, long long cc)
{
    long long skipped = 0;
    int seq[30]; // answer
    int used[30];
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; ++i) // calc the order number of position i
    {
        long long oldVal = skipped;
        int k;
        int No = 0;              // k is the No-th shortest of the left
        for (k = 1; k <= n; ++k) // at position i, length = k
        {
            oldVal = skipped;
            if (!used[k])
            {
                ++No;
                if (i == 1)
                {
                    skipped += f[No][n][HIGH] + f[No][n][LOW];
                }
                else
                {
                    if (k > seq[i - 1] && (i <= 2 || seq[i - 2] > seq[i - 1]))
                    {
                        skipped += f[No][n - i + 1][LOW];
                    }
                    else if (k < seq[i - 1] && (i <= 2 || seq[i - 2] < seq[i - 1]))
                    {
                        skipped += f[No][n - i + 1][HIGH];
                    }
                }
                if (skipped >= cc)
                {
                    break;
                }
            }
        }
        used[k] = true;
        seq[i] = k;
        skipped = oldVal;
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", seq[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    calc_ans();
    int k;
    scanf("%d", &k);
    int n;
    long long c;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%lld", &n, &c);
        Print(n, c);
    }
    return 0;
}
