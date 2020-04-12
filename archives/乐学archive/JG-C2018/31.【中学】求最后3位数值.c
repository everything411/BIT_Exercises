#include <stdio.h>
int main(int argc, char const *argv[])
{
    int base, power, answer;
    _Bool flag = 0;
    scanf("%d%d", &base, &power);
    answer = 1;
    for (int i = 0; i < power; i++)
    {
        answer *= base;
        if (answer > 999)
        {
            answer %= 1000;
            flag = 1;
        }
    }
    printf(flag ? "The last 3 numbers is %03d.\n" : "The last 3 numbers is %d.\n", answer);
    return 0;
}