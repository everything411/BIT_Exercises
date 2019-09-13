#include <cstdio>
#include <cstring>
#define MOD 998244353
#define MAXK 110
using namespace std;
struct matrix_t
{
    long long matrix[MAXK][MAXK];
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
matrix_t quick_power_mod(int power, matrix_t &mat_base, int size)
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
