#include <stdio.h>
int main(int argc, char const *argv[])
{
    int max;
    scanf("%d", &max);
    printf("%d\n", max < 4 ? max : max + 2);
    return 0;
}
