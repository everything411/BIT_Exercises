#include <stdio.h>
int calc(int stair);
int main(int argc, char const *argv[])
{
    int stair;
    scanf("%d", &stair);
    if (stair < 1)
    {
        puts("wrong input!");
        return 0;
    }
    int ans = calc(stair);
    printf(ans == 1 ? "There is %d way of climbing the stairs!\n" : "There are %d ways of climbing the stairs!\n", ans);
    return 0;
}

int calc(int stair)
{

    switch (stair)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 4;
    default:
        return calc(stair - 1) + calc(stair - 2) + calc(stair - 3);
    }
}