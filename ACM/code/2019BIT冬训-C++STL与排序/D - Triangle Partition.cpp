#include <iostream>
#include <algorithm>
using namespace std;
typedef struct point
{
    int x;
    int y;
    int id;
} point_t;
point_t points[3030];
bool operator<(point_t a, point_t b)
{
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}
int main(int argc, char const *argv[])
{
    int T;
    int tri_count, point_count;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &tri_count);
        point_count = 3 * tri_count;
        for (int i = 0; i < point_count; i++)
        {
            points[i].id = i + 1;
            scanf("%d%d", &points[i].x, &points[i].y);
        }
        sort(points, points + point_count);
        for (int i = 0; i < point_count; i += 3)
        {
            printf("%d %d %d\n", points[i].id, points[i + 1].id, points[i + 2].id);
        }
    }

    return 0;
}
