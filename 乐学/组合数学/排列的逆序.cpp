#include <iostream>
#include <cstring>
using namespace std;
int t[100];
int w[100];
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n, k;
        memset(t, 0, sizeof(t));
        memset(w, 0, sizeof(w));
        scanf("%d%d", &n, &k);
        k--;
        for (int i = 1; i <= n; i++)
        {
            t[n - i + 1] = k % i;
            k /= i;
        }
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            int j;
            for (j = 1;; j++)
            {
                if (!w[j])
                {
                    if (cnt >= t[i])
                    {
                        break;
                    }
                    cnt++;
                }
            }
            w[j] = i;
        }
        for (int i = 1; i < n; i++)
        {
            printf("%d ", w[i]);
        }
        printf("%d\n", w[n]);
    }

    return 0;
}
