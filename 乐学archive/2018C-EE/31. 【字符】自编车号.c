#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[10];
    int right = 1;
    int count;
    scanf("%s", str);
    right &= !!isdigit(str[4]);
    count = !!isupper(str[0]) + !!isupper(str[1]) + !!isupper(str[2]) + !!isupper(str[3]);
    right &= count > 1;
    right &= !(strchr(str, 'I') || strchr(str, 'O'));
    puts(right ? "ok." : "no.");
    return 0;
}
