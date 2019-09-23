#include <iostream>
using namespace std;
long long c[100][100];
void init() //求组合数
{
    for (int i = 0; i <= 80; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    int n;
    cin >> n;
    n--;
    cout << c[2 * n][n] << endl;
    return 0;
}
