#include <cstdio>
#include <cstring>
#define MOD 998244353
#define MAXK 4
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
matrix_t quick_power_mod(long long power, matrix_t &mat_base, int size)
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
void print(matrix_t &a, int size)
{
    fputs("\033[01;33;1m", stderr);
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            fprintf(stderr, "%lld ", a.matrix[i][j]);
        }
        putchar('\n');
    }
    fputs("\033[0m", stderr);
}
int main(int argc, char const *argv[])
{
    long long n;
    matrix_t fib;
    matrix_t mat;
    matrix_t ans;
    fib.matrix[1][1] = fib.matrix[1][2] = fib.matrix[1][3] = 1;
    mat.matrix[1][3] = mat.matrix[2][1] = mat.matrix[2][3] = mat.matrix[3][2] = mat.matrix[3][3] = 1;
    while (~scanf("%lld", &n))
    {
        ans = quick_power_mod(n - 1, mat, 3);
        ans = mul(fib, ans, 3);
        // print(ans, 3);
        printf("%lld\n", ans.matrix[1][1]);
        // printf("%lld\n",)
    }
    return 0;
}
