#include <iostream>
using namespace std;
void draw(int n, bool a)
{
    for (int i = 0; i < n - 1; i++)
    {
        putchar(' ');
    }
    putchar('*');
    if (a)
    {
        putchar('\n');
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n == 1)
    {
        puts("*");
        return 0;
    }
    draw(n, true);
    for (int i = 1; i < n; i++)
    {
        draw(n - i, false);
        draw(2 * i, true);
    }
    for (int i = n - 2; i > 0; i--)
    {
        draw(n - i, false);
        draw(2 * i, true);
    }
    draw(n, true);
    return 0;
}
