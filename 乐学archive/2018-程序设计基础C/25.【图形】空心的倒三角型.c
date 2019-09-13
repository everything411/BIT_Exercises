#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height,i;
    scanf("%d", &height);
    for (i = 0; i < 2 * height - 1; i++)
        putchar('*');
    putchar('\n');
    for (i = height - 1; i > 0; i--)
    {
        printf("%*c", height - i + 1, '*');
        if(i != 1)
            printf("%*c", 2 * i - 2, '*');
        putchar('\n');
    }
    return 0;
}
