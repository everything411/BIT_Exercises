#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MOD 9973
#define MAXK 16
#define MAXN 40010
using namespace std;
struct matrix_t
{
    int matrix[MAXK][MAXK];
    matrix_t(void)
    {
        memset(matrix, 0, sizeof(matrix));
    }
};
matrix_t mul(matrix_t &a, matrix_t &b, int size)
{
    matrix_t ans;
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
            for (int k = 1; k <= size; k++)
                ans.matrix[i][j] = (ans.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j]) % MOD;
    return ans;
}
matrix_t matrix_power_mod(int power, matrix_t &mat_base, int size)
{
    matrix_t ans;
    matrix_t tmp = mat_base;
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
            if (i == j)
                ans.matrix[i][j] = 1;
    while (power)
    {
        if (power & 1)
            ans = mul(ans, tmp, size);
        tmp = mul(tmp, tmp, size);
        power = power >> 1;
    }
    return ans;
}
int power_mod(int base, int power)
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base % MOD;
        base = base * base % MOD;
        power >>= 1;
    }
    return ans;
}
int is_prime[MAXN];
int prime[MAXN];
matrix_t mat;
int pnum = 0;
int m;
int n;
int k;
void init_prime()
{
    memset(is_prime, -1, sizeof(is_prime));
    for (int i = 2; i <= MAXN - 10; i++)
    {
        if (is_prime[i])
        {
            prime[pnum++] = i;
            for (int j = i * i; j <= MAXN - 10; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}
int euler(int c)
{
    int ans, x;
    ans = x = c;
    for (int i = 0; i < pnum && prime[i] * prime[i] <= c; i++)
    {
        if (x % prime[i] == 0)
        {
            ans = ans / prime[i] * (prime[i] - 1);
            while (x % prime[i] == 0)
            {
                x /= prime[i];
            }
        }
    }
    if (x > 1)
    {
        ans = ans / x * (x - 1);
    }
    return ans % MOD;
}
int cal(int len)
{
    int ret = 0;
    matrix_t t = matrix_power_mod(len, mat, m);
    for (int i = 1; i <= m; i++)
    {
        ret = ret + t.matrix[i][i];
    }
    return ret % MOD;
}
int polya(int n)
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                ans += cal(i) * euler(i);
                ans %= MOD;
            }
            else
            {
                ans += cal(i) * euler(n / i) + cal(n / i) * euler(i);
                ans %= MOD;
            }
        }
    }
    ans = ans * power_mod(n, MOD - 2);
    return ans % MOD;
}
int main(int argc, char const *argv[])
{
    init_prime();
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                mat.matrix[i][j] = 1;
            }
        }
        int u, v;
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d", &u, &v);
            mat.matrix[u][v] = mat.matrix[v][u] = 0;
        }
        int ans = polya(n);
        printf("%d\n", ans);
    }

    return 0;
}
