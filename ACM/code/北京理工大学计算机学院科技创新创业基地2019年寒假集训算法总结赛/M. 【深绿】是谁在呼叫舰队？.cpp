#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double f(double x)
{
    return x * log(x + 1);
}
int dist[100050];
int main(int argc, char const *argv[])
{
    int prev_pos = 0;
    int site_cnt;
    double ans = 0;
    int count = 0;
    scanf("%d", &site_cnt);
    site_cnt++;
    for (int i = 0; i < site_cnt; i++)
    {
        scanf("%d", &dist[i]);
    }
    for (int i = 0; i < site_cnt - 1; i++)
    {
        if (dist[i] >= dist[site_cnt - 1])
        {
            count++;
            dist[i] = 0x7fffffff;
        }
    }

    sort(dist, dist + site_cnt);
    site_cnt -= count;
    for (int i = 0; i < site_cnt; i++)
    {
        ans += f(dist[i] - prev_pos);
        prev_pos = dist[i];
    }
    printf("%.10lf\n", ans);
    return 0;
}