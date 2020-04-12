/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
#include <stdlib.h>
void reverse(char *str, int start, int end);
char *gets(char *);
int main()
{
    char str[100];
    int start, end;
    gets(str);
    scanf("%d%d", &start, &end);
    reverse(str, start, end);
    printf("%s\n", str);
    return 0;
}

     PRESET CODE END - NEVER TOUCH CODE ABOVE */
size_t strlen(const char *s);
void reverse(char *str, int start, int end)
{
    int len = strlen(str);
    if (start >= len)
        start = len - 1;
    if (end >= len)
        end = len - 1;
    char ch;
    ch = str[start];
    str[start] = str[end];
    str[end] = ch;
    if (start < end - 1)
        reverse(str, start + 1, end - 1);
}