#include <iostream>
#include <cstring>
#define MAXN 110
using namespace std;
int n;
int q[MAXN];
int m[MAXN][MAXN];
int s[MAXN][MAXN];
void traceback(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        putchar('(');
        traceback(i, s[i][j]);
        traceback(s[i][j] + 1, j);
        putchar(')');
    }
}
int main(int argc, char const *argv[])
{

    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &q[i]);
    }
    // memset(m,0,sizeof(m));

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            int k = i + j;
            s[j][k] = j;
            m[j][k] = m[j][j] + m[j + 1][k] + q[j - 1] * q[j] * q[k];
            for (int l = j + 1; l <= k - 1; l++)
            {
                int t = m[j][l] + m[l + 1][k] + q[j - 1] * q[l] * q[k];
                if (m[j][k] > t)
                {
                    m[j][k] = t;
                    s[j][k] = l;
                }
            }
        }
    }
    printf("%d\n", m[1][n]);
    if (n == 1)
    {
        puts("(A1)");
    }
    else
    {
        traceback(1, n);
        putchar('\n');
    }
    return 0;
}
