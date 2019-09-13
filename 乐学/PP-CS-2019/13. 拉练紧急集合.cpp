#include <iostream>
#include <algorithm>
#define LL_MAX 9223372036854775807LL
#define UPLEFT 0
#define DOWNLEFT 1
#define UPRIGHT 2
#define DOWNRIGHT 3
using namespace std;
struct coordinate
{
    long long x;
    long long y;
    void set(long long a, long long b)
    {
        x = a;
        y = b;
    }
};
long long manhattan_dist(const coordinate &a, const coordinate &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}
long long length, width;
int dormitory_count;
int target_count;
long long min_val[4] = {LL_MAX, LL_MAX, LL_MAX, LL_MAX};
coordinate min_coordinate[4];
long long len_buf[4];
int main(void)
{
    long long dist_tmp;
    long long max_dist = LL_MAX;
    coordinate corner[4];
    coordinate coor;
    scanf("%lld%lld", &length, &width);
    scanf("%d", &dormitory_count);
    corner[UPLEFT].set(0, width);
    corner[UPRIGHT].set(length, width);
    corner[DOWNLEFT].set(0, 0);
    corner[DOWNRIGHT].set(length, 0);
    for (int i = 0; i < dormitory_count; i++)
    {
        scanf("%lld%lld", &coor.x, &coor.y);
        for (int i = 0; i < 4; i++)
        {
            if ((dist_tmp = manhattan_dist(coor, corner[i])) < min_val[i])
            {
                min_val[i] = dist_tmp;
                min_coordinate[i] = coor;
            }
        }
    }
    scanf("%d", &target_count);
    for (int i = 0; i < target_count; i++)
    {
        scanf("%lld%lld", &coor.x, &coor.y);
        for (int i = 0; i < 4; i++)
        {
            len_buf[i] = manhattan_dist(min_coordinate[i], coor);
        }
        sort(len_buf, len_buf + 4);
        max_dist = min(len_buf[3], max_dist);
    }
    printf("%lld\n", max_dist);
    return 0;
}