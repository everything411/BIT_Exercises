#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height;
    scanf("%d", &height);
    printf("%*c\n", height, '*');
    for (int i = 1; i < height - 1; i++)
        printf("%*c%*c\n", height - i, '*', 2 * i, '*');
    if (height != 1)
    {
        for (int i = 0; i < 2 * height - 1; i++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
