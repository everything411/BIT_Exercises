#include <stdio.h>
int main(void)
{
    int height, width, count;
    char ch;
    int x, y;
    x = y = 0;
    scanf("%d%d%d", &height, &width, &count);
    for (int i = 0; i < count; i++)
    {
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;

        default:
            break;
        }
        if (x >= width || y >= height || x < 0 || y < 0)
        {
            puts("invalid");
            return 0;
        }
    }
    puts("valid");
    return 0;
}