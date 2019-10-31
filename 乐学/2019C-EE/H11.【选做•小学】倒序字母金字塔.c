#include <stdio.h>
#include <ctype.h>
char c;
int a, h;
int count = 0;
int ch;
int lowerflag = 0;
void check(void)
{
    if (lowerflag)
    {
        if (ch > 'z')
        {
            ch = 'a';
        }
        if (ch < 'a')
        {
            ch = 'z';
        }
    }
    else
    {
        if (ch > 'Z')
        {
            ch = 'A';
        }
        if (ch < 'A')
        {
            ch = 'Z';
        }
    }
}
void putcharcnt(int ch)
{
    if (ch == 'z' || ch == 'Z')
    {
        count++;
    }
    putchar(ch);
}
int main(int argc, char const *argv[])
{
    scanf("%c%d%d", &c, &a, &h);
    lowerflag = islower(c);
    for (int i = 0; i < h; i++)
    {
        ch = c;
        for (int j = 0; j < h - i - 1; j++)
        {
            putchar(' ');
        }
        for (int j = 0; j < a / 2 + i; j++)
        {
            putcharcnt(ch);
            ch--;
            check();
        }
        if (a & 1)
        {
            putcharcnt(ch);
        }

        for (int j = 0; j < a / 2 + i; j++)
        {
            ch++;
            check();
            putcharcnt(ch);
        }
        putchar('\n');
    }
    printf("所建金字塔共使用%d个字母砖块%c\n", count, lowerflag ? 'z' : 'Z');
    return 0;
}
