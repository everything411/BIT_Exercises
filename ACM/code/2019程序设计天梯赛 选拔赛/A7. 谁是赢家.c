#include <stdio.h>
int main(int argc, char const *argv[])
{
    int audience_a, audience_b;
    int judge_a, judge_b;
    int judge_val;
    judge_a = judge_b = 0;
    scanf("%d%d", &audience_a, &audience_b);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &judge_val);
        if (judge_val == 0)
        {
            judge_a++;
        }
        else
        {
            judge_b++;
        }
    }
    if ((audience_a > audience_b && judge_a != 0) || judge_a == 3)
    {
        printf("The winner is a: %d + %d\n", audience_a, judge_a);
    }
    else
    {
        printf("The winner is b: %d + %d\n", audience_b, judge_b);
    }
    return 0;
}
