#include <iostream>
#include <algorithm>
using namespace std;
struct house_t
{
    int cat_food;
    int JavaBean_weight;
    double rate;
};
bool operator<(house_t a, house_t b)
{
    return a.rate > b.rate;
}
house_t houses[1000];
int main(int argc, char const *argv[])
{
    int food_weight;
    int house_count;
    double ans;
    while (scanf("%d%d", &food_weight, &house_count) && ~house_count)
    {
        ans = 0;
        for (int i = 0; i < house_count; i++)
        {
            scanf("%d%d", &houses[i].JavaBean_weight, &houses[i].cat_food);
            houses[i].rate = (double)houses[i].JavaBean_weight / houses[i].cat_food;
        }
        sort(houses, houses + house_count);
        for (int i = 0; i < house_count && food_weight != 0; i++)
        {

            if (food_weight >= houses[i].cat_food)
            {
                food_weight -= houses[i].cat_food;
                ans += houses[i].JavaBean_weight;
            }
            else
            {
                ans += houses[i].JavaBean_weight * ((double)food_weight / houses[i].cat_food);
                food_weight = 0;
            }
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}
