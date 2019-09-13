#include <iostream>
#define MOD 1000000007
using namespace std;
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
                ans.matrix[i][j] = (ans.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j]) % MOD;
    return ans;
}
long long fib(long long power)
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
    long long hp_1, hp_2, hp_3, max_rec;
    cin >> hp_1 >> hp_2 >> hp_3 >> max_rec;
    if (hp_1 == 0)
    {
        max_rec = 1;
    }
    else if (hp_2 == 0 && max_rec > 2)
    {
        max_rec = 2;
    }
    else if (hp_3 == 0 && max_rec > 3)
    {
        max_rec = 3;
    }
    if (max_rec == 1)
    {
        cout << hp_1 % MOD << endl;
    }
    else if (max_rec == 2)
    {
        cout << (hp_1 + hp_2) % MOD << endl;
    }
    else if (max_rec == 3)
    {
        cout << (hp_1 + hp_2 + hp_3) % MOD << endl;
    }
    else
    {
        cout << (hp_1 + fib(max_rec - 1) * hp_2 + fib(max_rec) * hp_3 - hp_3) % MOD << endl;
    }

    return 0;
}
