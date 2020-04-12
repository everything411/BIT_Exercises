#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char ch = getchar();
    if (isdigit(ch))
        puts("Digital.");
    else if (isupper(ch))
        puts("Upper case letter.");
    else if (islower(ch))
        puts("Lower case letter.");
    else
        puts("Other.");
    return 0;
}
