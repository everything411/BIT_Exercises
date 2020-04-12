#include <iostream>
#include <cstring>
using namespace std;
long long sweets[100010];
int t_visited[100010];

int main(int argc, char const *argv[])
{
    int c;
    int n;
    long long sum;
    long long t;
    while (~scanf("%d%d", &c, &n) && c && n)
    {
        sum = 0;
        memset(t_visited, -1, sizeof(t_visited));
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", sweets + i);
        }
        for (int i = 0; i < n; i++)
        {
            sum += sweets[i];
            t = sum % c;
            if (t == 0)
            {
                for (int j = 0; j < i; j++)
                {
                    printf("%lld ", sweets[j]);
                }
                printf("%lld\n", sweets[i]);
                break;
            }

            if (t_visited[t] != -1)
            {
                for (int j = t_visited[t] + 1; j < i; j++)
                {
                    printf("%lld ", sweets[j]);
                }
                printf("%lld\n", sweets[i]);
                break;
            }
            t_visited[t] = i;
        }
    }

    return 0;
}
