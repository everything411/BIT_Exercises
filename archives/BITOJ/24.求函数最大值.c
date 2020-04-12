#include <stdio.h>
#include <math.h>
#define PI 3.141592654
// f(x)=asin^2(x)+bcos^2(x)+csinx+dcosx
double f(double a, double b, double c, double d, double x)
{
    static double sin_val, cos_val;
    sin_val = sin(x);
    cos_val = cos(x);
    return a * sin_val * sin_val + b * cos_val * cos_val + c * sin_val + d * cos_val;
}
int main(int argc, char const *argv[])
{
    double a, b, c, d;
    double L, R;
    double max_val = -1e16;
    double ret_val;
    scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &L, &R);
    if (fabs(R - L) < 0.0001)
    {
        printf("%.1lf\n", f(a, b, c, d, L));
        return 0;
    }
    if (R - L > 2 * PI)
        R = L + 2 * PI;
    for (double i = L; i < R; i += 0.0001)
        if ((ret_val = f(a, b, c, d, i)) > max_val)
            max_val = ret_val;
    printf("%.1lf\n", max_val);
    return 0;
}
