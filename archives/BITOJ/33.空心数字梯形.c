#include <stdio.h>
int main(int argc, char const *argv[])
{
    int height;
    int ch = 0;
    int i;
    scanf("%d%d", &height, &ch);
    if (height == 1)
    {
        printf("%d\n", ch);
        return 0;
    }
    for (i = 0; i < ((height % 2) ? (3 * height / 2) : (3 * height / 2 - 1)); i++)
        printf("%d", ch++ % 10);
    if (!(height % 2))
        printf("%d", --ch % 10);
    ch -= (height % 2) ? 2 : 1;
    for (i = 0; i < 3 * height - 3 - 3 * height / 2; i++)
        printf("%d", ch-- % 10);
    printf("%d\n", ch++ % 10);

    for (i = height - 2; i > 0; i--)
    {
        printf("%*d%*d\n", height - i, ch % 10, i * 2 + height - 1, ch % 10);
        ch++;
    }

    printf("%*c", height - 1, ' ');
    for (i = 0; i < height / 2; i++)
        printf("%d", ch++ % 10);
    if (height % 2)
        printf("%d", ch % 10);
    ch--;
    for (i = 0; i < ((height % 2) ? (height - height / 2 - 1) : (height - height / 2)) - 1; i++)
        printf("%d", ch-- % 10);
    printf("%d\n", ch % 10);
    return 0;
}