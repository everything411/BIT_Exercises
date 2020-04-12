#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    int sub1, sub2, sub3;
    scanf("%d", &num);
    for (int i = 10000; i < 30001; i++)
    {
        sub1 = i / 100;
        sub2 = i / 10 % 1000;
        sub3 = i % 1000;
        if (!(sub1 % num || sub2 % num || sub3 % num))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}