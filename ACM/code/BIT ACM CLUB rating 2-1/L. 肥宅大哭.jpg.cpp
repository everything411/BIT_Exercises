#include <iostream>
#include <algorithm>
using namespace std;
struct problem_t
{
    long long time;
    long long difficulty;
} problems[100010];
bool operator<(problem_t &a, problem_t &b)
{
    return a.difficulty < b.difficulty;
}
int main(void)
{
    int case_cnt;
    int len, problem_cnt;
    scanf("%d", &case_cnt);
    for (int i = 0; i < case_cnt; i++)
    {
        scanf("%d%d", &problem_cnt, &len);
        for (int i = 0; i < problem_cnt; i++)
        {
            scanf("%lld", &problems[i].difficulty);
        }
        for (int i = 0; i < problem_cnt; i++)
        {
            scanf("%lld", &problems[i].time);
        }
        sort(problems, problems + problem_cnt);
        long long ans = 0;
        int j;
        for (j = 0; j < problem_cnt; j++)
        {
            if ((ans += problems[j].time) > len)
            {
                break;
            }
        }
        printf("Case %d: %d\n", i + 1, j);
    }

    return 0;
}