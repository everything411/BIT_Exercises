#include <stdio.h>
int main(int argc, char const *argv[])
{
    int numbers[10];
    int order[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int flag;
    for (int i = 0; i < 10; i++)
        scanf("%d", &numbers[i]);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            if (numbers[i] > numbers[j])
            {
                flag = 1;

                for (int k = 0; k < j; k++)
                {

                    if (numbers[j] == numbers[k])
                    {
                        flag = 0;
                    }
                }
                if (flag)
                    order[i]++;
            }
    }
    for (int i = 0; i < 10; i++)
        printf(i == 9 ? "%d\n" : "%d,", order[i]);
    return 0;
}