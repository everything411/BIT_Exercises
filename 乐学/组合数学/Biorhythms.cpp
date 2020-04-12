#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int p, e, i, d;
    const int lcm = 21252; // lcm(23,28,33)
    int cnt = 1;
    while (~scanf("%d%d%d%d", &p, &e, &i, &d))
    {
        if (p == -1 && e == -1 && i == -1 && d == -1)
        {
            break;
        }
        int n = (5544 * p + 14421 * e + 1288 * i - d + lcm) % lcm;
        if (n == 0)
        {
            n = 21252;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", cnt++, n);
    }

    return 0;
}
