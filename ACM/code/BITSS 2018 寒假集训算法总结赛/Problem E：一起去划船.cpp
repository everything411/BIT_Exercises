#include <iostream>
#include <algorithm>
using namespace std;
long long wait_queue[100010];
int main(int argc, char const *argv[])
{
    int case_count;
    int girls_count;
    int ans;
    long long wait_time;
    long long wait_sum = 0;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        ans = 0;
        wait_sum = 0;
        scanf("%d", &girls_count);
        for (int i = 0; i < girls_count; i++)
        {
            scanf("%lld", &wait_time);
            wait_queue[i] = wait_time;
        }
        sort(wait_queue, wait_queue + girls_count);
        for (int i = 0; i < girls_count; i++)
        {
            if (wait_queue[i] >= wait_sum)
            {
                ans++;
                wait_sum += wait_queue[i];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
