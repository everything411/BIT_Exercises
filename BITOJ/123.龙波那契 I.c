#include <stdio.h>
long long calc(int stair);
int main(int argc, char const *argv[])
{
    int stair;
    while (~scanf("%d", &stair))
        printf("%lld\n", calc(stair));
    return 0;
}

long long calc(int stair)
{
    switch (stair)
    {
    case 1:
    case 2:
    case 3:
        return 1;
    default:
        return calc(stair - 1) + calc(stair - 2) + calc(stair - 3);
    }
}