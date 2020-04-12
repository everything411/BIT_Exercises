#include <iostream>
using namespace std;
char *keyboard[] = {
    "qwertyuiop",
    "asdfghjkl;",
    "zxcvbnm,./"};
char rmap[128];
char lmap[128];
void init(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            rmap[keyboard[i][j]] = keyboard[i][j - 1];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            lmap[keyboard[i][j]] = keyboard[i][j + 1];
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    char ch;
    ch = getchar();
    getchar();
    if (ch == 'R')
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            putchar(rmap[ch]);
        }
    }
    else
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            putchar(lmap[ch]);
        }
    }
    putchar('\n');
    return 0;
}
