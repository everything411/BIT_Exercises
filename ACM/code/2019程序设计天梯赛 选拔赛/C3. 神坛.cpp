#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct point
{
    int x;
    int y;
} point_t;
bool operator<(point_t a, point_t b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }
    else
    {
        return a.x < b.x;
    }
}
bool operator==(point_t a, point_t b)
{
    return a.x == b.x && a.y == b.y;
}
long double triangle_area(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3)
{
    //cout << (((x1) * (y2) + (x2) * (y3) + (x3) * (y1) - (y1) * (x2) - (y2) * (x3) - (y3) * (x1)) / 2.0) << endl;
    return (((x1) * (y2) + (x2) * (y3) + (x3) * (y1) - (y1) * (x2) - (y2) * (x3) - (y3) * (x1)) / 2.0);
}
int main(int argc, char const *argv[])
{
    int dot_count;
    long double area_min = 1e20;
    long double area_ans;
    scanf("%d", &dot_count);
    point_t dots[dot_count];
    for (int i = 0; i < dot_count; i++)
        scanf("%d%d", &dots[i].x, &dots[i].y);
    sort(dots, dots + dot_count);

    for (int i = 1; i < dot_count; i++)
    {
        if (dots[i - 1] == dots[i])
        {
            puts("0.000");
            return 0;
        }
    }

    for (int i = 0; i < dot_count; i++)
        for (int j = i + 1; j < dot_count; j++)
            for (int k = j + 1; k < dot_count; k++)
                if ((area_ans = fabsl(triangle_area(dots[i].x, dots[i].y, dots[j].x, dots[j].y, dots[k].x, dots[k].y))) < area_min)
                    area_min = area_ans;
    //cout << area_min << endl;
    //printf("%.3lF\n", area_min);
    printf("%.3f\n", (double)area_min);
    return 0;
}
