#include <stdio.h>
#include <math.h>
long long x, y, n;
long double real_val;
long double curr_min = 0x3f3f3f3f;
long double xtmp;
long long xans, yans;
int main(int argc, char const *argv[])
{
    scanf("%lld%lld%lld", &x, &y, &n);
    real_val = (long double)x / (long double)y;
    for (int ytmp = 1; ytmp <= n; ytmp++)
    {
        xtmp = (long long)(real_val * ytmp);
        if (real_val * ytmp - (long long)(real_val * ytmp) > 0.5)
        {
            xtmp++;
        }
        if (fabs(xtmp / ytmp - real_val) < curr_min)
        {
            curr_min = fabs(xtmp / ytmp - real_val);
            xans = xtmp;
            yans = ytmp;
        }
    }
    printf("%lld/%lld\n", xans, yans);
    return 0;
}
