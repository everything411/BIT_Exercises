/*#include <stdio.h>
#include <math.h>
long double length(long double x1, long double y1, long double x2, long double y2);
long double area(long double *);
int main(int argc, char const *argv[])
{
    long double x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("(%llf,%llf)(%llf,%llf)(%llf,%llf)(%llf,%llf)", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    long double triangle_one[3], triangle_two[3];
    triangle_one[0] = length(x1, y1, x2, y2);
    triangle_one[1] = length(x1, y1, x3, y3);
    triangle_one[2] = length(x3, y3, x2, y2);
    triangle_two[0] = length(x2, y2, x4, y4);
    triangle_two[1] = length(x3, y3, x4, y4);
    triangle_two[2] = triangle_one[2];
    printf("%.2llf\n", area(triangle_one) + area(triangle_two));
    return 0;
}
long double length(long double x1, long double y1, long double x2, long double y2)
{
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
long double area(long double *tri)
{
    long double p = (tri[0] + tri[1] + tri[2]) / 2.0;
    return sqrtl(p * (p - tri[0]) * (p - tri[1]) * (p - tri[2]));
}*/
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("(%lf,%lf)(%lf,%lf)(%lf,%lf)(%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    printf("%.2lf\n", fabs((x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2 + x1 * y3 + x3 * y4 + x4 * y1 - x1 * y4 - x3 * y1 - x4 * y3) / 2));
    return 0;
}
