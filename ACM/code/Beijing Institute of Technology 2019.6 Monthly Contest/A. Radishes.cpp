#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct radish_t
{
    double len;
    double wei;
    int order;
};
bool operator==(radish_t a, radish_t b)
{
    return (a.wei > b.wei) ? (a.wei / b.wei * abs(a.len - b.len)) : (b.wei / a.wei * abs(a.len - b.len));
}
radish_t radishes[100001];
int main(void)
{
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        radishes[i].order = i + 1;
        scanf("%lf%lf", &radishes[i].len, &radishes[i].wei);
    }
    sort(radishes, radishes + cnt);
    double minval = 1e5;
    for (int i = 0; i < cnt - 1; i++)
    {
        if (radishes[i + 1] - radishes[i] < minval)
        {
            /* code */
        }
    }
}