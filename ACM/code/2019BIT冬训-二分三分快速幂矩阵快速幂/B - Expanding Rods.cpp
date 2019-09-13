#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-7;
double iL, t, c, Ls;
bool C(double m)
{
    double r = m + iL * iL / (4.0 * m);
    return asin(iL / r) * r >= Ls;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%lf%lf%lf", &iL, &t, &c))
    {
        if (iL < 0 || t < 0 || c < 0)
            break;
        Ls = (1.0 + t * c) * iL;
        double lb = 0, ub = iL / 2.0;
        while (ub - lb > eps)
        {
            double mid = (ub + lb) / 2.0;
            if (C(mid))
            {
                ub = mid;
            }
            else
                lb = mid;
        }
        printf("%.3lf\n", ub);
    }
    return 0;
}