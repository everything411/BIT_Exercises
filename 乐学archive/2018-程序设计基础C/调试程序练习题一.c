#include <stdio.h>
//BUG string length error
extern char *gets(char *);
void reverse(char *str, int start, int end)
{
    char temp;
    if (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        reverse(str, start + 1, end - 1);
    }
}
int main(void)
{
    int len = 0;
    char str[100];
    gets(str);
    while (str[len] != '\0')
        len++;
    reverse(str, 0, len - 1);
    puts(str);
    return 0;
}