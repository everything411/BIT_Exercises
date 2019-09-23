#include <stdio.h>
int up, down;
int _ch;
int nextch(void)
{
    return _ch++ % 26 + 'A';
}
void putnch(int ch, int n)
{
    for (int i = 0; i < n; i++)
    {
        putchar(ch);
    }
}
int main(int argc, char const *argv[])
{
    char ch;
    scanf("%d%d %c", &up, &down, &ch);
    _ch = ch - 'A';
    ch = nextch();
    putnch(' ', (down - up) / 2);
    putnch(ch, up);
    putnch('\n', 1);
    for (int i = 1; i < (down - up) / 2; i++)
    {
        ch = nextch();
        putnch(' ', (down - up) / 2 - i);
        putnch(ch, 1);
        putnch(' ', 2 * (i - 1) + up);
        putnch(ch, 1);
        putnch('\n', 1);
    }
    ch = nextch();
    putnch(ch, down);
    putnch('\n', 1);
    return 0;
}
