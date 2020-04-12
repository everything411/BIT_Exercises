#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 100010
using namespace std;
struct point
{
    double x;
    double y;
    bool operator<(const point &b) const
    {
        if (x != b.x)
        {
            return x < b.x;
        }
        else
        {
            return y < b.y;
        }
    }
    double distance(const point &b) const
    {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
};
point c[MAXN];
int pindex[MAXN];
bool cmp(const int a, const int b)
{
    if (c[a].y != c[b].y)
    {
        return c[a].y < c[b].y;
    }
    else
    {
        return c[a].x < c[b].x;
    }
}
double calc_min(int l, int r)
{
    switch (r - l)
    {
    case 0:
        return 0.0;
    case 1:
        return c[l].distance(c[r]);
    case 2:
    {
        double m;
        m = min(c[l].distance(c[l + 1]), c[l + 1].distance(c[l + 2]));
        m = min(m, c[l].distance(c[l + 2]));
        return m;
    }
    default:
    {
        int mid = (l + r) / 2;
        point midpoint = c[mid];
        double lmin, rmin;
        lmin = calc_min(l, mid);
        rmin = calc_min(mid + 1, r);
        double lrmin = min(lmin, rmin);
        int t = 0;
        for (int i = mid; i >= l && midpoint.x - c[i].x <= lrmin; i--)
        {
            pindex[t++] = i;
        }
        for (int i = mid + 1; i <= r && c[i].x - midpoint.x <= lrmin; i++)
        {
            pindex[t++] = i;
        }
        sort(pindex, pindex + t, cmp);
        for (int i = 0; i < t; i++)
        {
            for (int j = i + 1; j < t && j <= i + 7; j++)
            {
                lrmin = min(lrmin, c[pindex[i]].distance(c[pindex[j]]));
            }
        }
        return lrmin;
    }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &c[i].x, &c[i].y);
        }
        sort(c, c + n);
        double ans = calc_min(0, n - 1);
        printf("%.2f\n", ans / 2);
    }

    return 0;
}
