#include <cstdio>
#include <algorithm>
using namespace std;
long long stall_pos[100000];
int main(int argc, char const *argv[])
{
    int stall_count, cow_count;
    scanf("%d%d", &stall_count, &cow_count);
    for (int i = 0; i < stall_count; i++)
    {
        scanf("%lld", stall_pos + i);
    }
    sort(stall_pos, stall_pos + stall_count);

    long long left = 0;
    long long int right = stall_pos[stall_count - 1] + 1;
    while (right - left > 1)
    {
        long long last = 0, count = 1;
        long long mid = (left + right) / 2;
        for (int i = 1; i < stall_count; i++)
        {
            if (stall_pos[i] - stall_pos[last] > mid)
            {
                last = i;
                count++;
            }
        }
        if (count < cow_count)
            right = mid;
        else
            left = mid;
    }
    printf("%lld\n", right);
    return 0;
}
