#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char upper[2048];
char lower[2048];
int upper_pos, lower_pos;
int ch_cmp(const void *ch_1, const void *ch_2)
{
    return *(const char *)ch_1 > *(const char *)ch_2 ? 1 : -1;
}
inline static void upper_push(char value)
{
    upper[upper_pos++] = value;
}
inline static void lower_push(char value)
{
    lower[lower_pos++] = value;
}
int main(int argc, char const *argv[])
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            lower_push(ch);
            break;
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            upper_push(ch);
            break;
        }
    }
    qsort(upper, upper_pos, sizeof(char), ch_cmp);
    qsort(lower, lower_pos, sizeof(char), ch_cmp);
    printf("%s%s\n", lower, upper);
    return 0;
}
