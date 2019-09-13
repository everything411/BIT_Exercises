#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height;
    scanf("%d", &height);

    for (size_t i = 1; i < height; i++)
    {
        printf("%*c", height - i + 1, '*');
        if(i != 1)
            printf("%*c", 2 * i - 2, '*');
        putchar('\n');
    }

    for (size_t i = 0; i < 2 * height - 1; i++)
    {
        putchar('*');
    }
    putchar('\n');

    return 0;
}
