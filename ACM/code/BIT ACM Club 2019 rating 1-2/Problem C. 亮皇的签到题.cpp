#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
inline static long double triangle_area(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    return (long double)llabs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2.0;
}
bool cmp(long double a, long double b)
{
    return a > b;
}
long long dot_x[1000], dot_y[1000];
long double areas[200000];
int main(int argc, char const *argv[])
{
    int case_count;
    int dot_count;
    int ans_count;
    int rank;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        ans_count = 0;
        scanf("%d%d", &dot_count, &rank);
        for (int i = 0; i < dot_count; i++)
            scanf("%lld%lld", dot_x + i, dot_y + i);
        for (int i = 0; i < dot_count; i++)
            for (int j = i + 1; j < dot_count; j++)
                for (int k = j + 1; k < dot_count; k++)
                    areas[ans_count++] = triangle_area(dot_x[i], dot_y[i], dot_x[j], dot_y[j], dot_x[k], dot_y[k]);
        nth_element(areas, areas + rank - 1, areas + ans_count, cmp);

        printf("%.2Lf\n", *(areas + rank - 1));
    }
    return 0;
}
