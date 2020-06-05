#include <iostream>
using namespace std;
int f[30]; // the number of tilings of a 3xN rectangle
int g[30]; // the number of tilings of a 3xN rectangle with one of its corner squares removed
void calc_ans()
{
    f[0] = 1;
    f[1] = 0;
    g[0] = 0;
    g[1] = 1;
    for (int i = 2; i < 30; i++)
    {
        f[i] = f[i - 2] + 2 * g[i - 1];
        g[i] = f[i - 1] + g[i - 2];
    }
}
int main(int argc, char const *argv[])
{
    calc_ans();
    int n;
    while (~scanf("%d", &n) && n != -1)
    {
        if (n & 1)
        {
            puts("0");
        }
        else
        {
            printf("%d\n", f[n]);
        }
    }

    return 0;
}
