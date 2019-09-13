#include <cstdio>
using namespace std;
int main(int argc, char *argv[])
{
    int num_cnt, case_cnt;
    int tmp;
    scanf("%d", &case_cnt);
    for (int j = 0; j < case_cnt; j++)
    {
        scanf("%d", &num_cnt);
        int sum = 0, maxsum = -1001, first = 0, last = 0, temp = 1;
        for (int i = 0; i < num_cnt; i++)
        {
            scanf("%d", &tmp);
            sum += tmp;
            if (sum > maxsum)
            {
                maxsum = sum;
                first = temp;
                last = i + 1;
            }
            if (sum < 0)
            {
                sum = 0;
                temp = i + 2;
            }
        }
        printf("Case %d:\n%d %d %d\n", j + 1, maxsum, first, last);
        if (j != case_cnt - 1)
        {
            printf("\n");
        }
    }
    return 0;
}