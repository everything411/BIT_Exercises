#include <stdio.h>
#include <ctype.h>
char *list[] = {"2", "19", "11", "21", "12", "3", "20", "9", "13", "1", "18", "10", "22", "6", "23", "14", "7", "24", "15", "8", "16", "26", "25", "4", "17", "5"};
int main(int argc, char const *argv[])
{
    char ch;
    while (~(ch = getchar()))
    {
        if (isupper(ch))
        {
            fputs(list[ch - 'A'], stdout);
        }
        else
        {
            putchar(ch);
        }
    }
    return 0;
}
