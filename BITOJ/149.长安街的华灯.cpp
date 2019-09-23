#include <iostream>
#define PI 3.141592654
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    long long n, l, r;
    double ans;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%lld%lld%lld", &n, &l, &r);
        if (2 * r >= l)
        {
            ans = PI * r * r * n;
        }
        else
        {
            /* code */
        }
        printf("%f\n", ans);
    }

    return 0;
}
