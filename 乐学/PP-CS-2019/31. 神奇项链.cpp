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
int get_ans(matrix_t &mat, int size)
{
    int ans = 0;
    for (int i = 1; i <= size; i++)
    {
        ans = (ans + mat.matrix[i][i] + mat.matrix[i][i + 1] + mat.matrix[i][i - 1]) % MOD;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    int cnt, max_pow;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &cnt, &max_pow);
        matrix_t mat;
        for (int i = 1; i <= max_pow; i++)
        {
            mat.matrix[i][i] = mat.matrix[i][i - 1] = mat.matrix[i][i + 1] = 1;
        }
        matrix_t ans = quick_power_mod(cnt - 1, mat, max_pow);
        printf("%d\n", get_ans(ans, max_pow));
    }
    return 0;
}
