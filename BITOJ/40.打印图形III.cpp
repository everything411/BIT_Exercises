#include <iostream>
#include <cassert>
using namespace std;
int str[50];
int n;
char a;
void draw_space(int n)
{
    for (int i = 0; i < n; i++)
    {
        putchar(' ');
    }
}
void init(void)
{
    assert(n + a - 1 <= 'Z');
    for (int i = 0; i < n; i++)
    {
        str[n - i] = str[n + i] = a + i;
    }
}

int main(int argc, char const *argv[])
{

    scanf("%d %c", &n, &a);
    if (n == 1)
    {
        putchar(a);
        putchar('\n');
        return 0;
    }
    init();
    draw_space(n - 1);
    putchar(str[n]);
    putchar('\n');
    for (int i = 1; i < n - 1; i++)
    {
        draw_space(n - i - 1);
        putchar(str[n - i]);
        draw_space(2 * i - 1);
        putchar(str[n + i]);
        putchar('\n');
    }
    for (int i = 1; i < n * 2; i++)
    {
        putchar(str[i]);
    }
    putchar('\n');
    return 0;
}
