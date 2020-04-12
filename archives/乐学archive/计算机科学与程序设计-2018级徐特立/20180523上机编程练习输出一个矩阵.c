#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            printf("%2d", j < i ? 1 : j - i + 1);
        putchar('\n');
    }
    return 0;
}
