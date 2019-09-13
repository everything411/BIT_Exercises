#include <stdio.h>
#include <math.h>
double triangle_area(double, double, double, double, double, double);
int main(int argc, char const *argv[])
{
    int case_count;
    int dot_count;
    double area_max = 0.0;
    double area_ans;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; area_max = 0.0, i++)
    {
        scanf("%d", &dot_count);
        int dot_x[dot_count], dot_y[dot_count];
        for (int i = 0; i < dot_count; i++)
            scanf("%d%d", dot_x + i, dot_y + i);
        for (int i = 0; i < dot_count; i++)
            for (int j = i + 1; j < dot_count; j++)
                for (int k = j + 1; k < dot_count; k++)
                    if ((area_ans = fabs(triangle_area(dot_x[i], dot_y[i], dot_x[j], dot_y[j], dot_x[k], dot_y[k]))) > area_max)
                        area_max = area_ans;
        printf("%.1f\n", area_max);
    }

    return 0;
}

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2.0;
}