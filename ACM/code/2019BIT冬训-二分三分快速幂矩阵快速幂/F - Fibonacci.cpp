#include <cstdio>
using namespace std;
#define mod 10000
struct matrix_t
{
    long long matrix[2][2];
    matrix_t(void)
    {
        matrix[0][0] = 1;
        matrix[0][1] = 1;
        matrix[1][0] = 1;
        matrix[1][1] = 0;
    }
};
matrix_t mul(matrix_t a, matrix_t b)
{
    matrix_t ans;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            ans.matrix[i][j] = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                ans.matrix[i][j] = (ans.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j]) % mod;
    return ans;
}
long long quick_power_mod(int power)
{
    matrix_t ans, tmp;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (i == j)
                ans.matrix[i][j] = 1;
            else
                ans.matrix[i][j] = 0;
    while (power)
    {
        if (power & 1)
            ans = mul(ans, tmp);
        tmp = mul(tmp, tmp);
        power = power >> 1;
    }
    return ans.matrix[1][0];
}
int main(int argc, char const *argv[])
{
    long long n;
    while (scanf("%lld", &n) && ~n)
        printf("%lld\n", quick_power_mod(n));
    return 0;
}
