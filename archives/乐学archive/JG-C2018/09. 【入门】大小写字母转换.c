#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    scanf("%c", &ch);
    printf("%c\n", ch >= 'A' && ch <= 'Z' ? tolower(ch) : toupper(ch));
    return 0;
}