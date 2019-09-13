#include <stdio.h>
inline static int fast_read(void)
{
    _Bool negative = 0;
    register int ch;
    register int number = 0;
    ch = getchar();
    switch (ch)
    {
    case '\n':
        return 10001;
    case EOF:
        return 10002;
    }
    if (ch == '-')
    {
        negative = 1;
        ch = getchar();
    }
    for (; ((ch > '0' - 1) && (ch < '9' + 1)); ch = getchar())
        number = number * 10 + ch - '0';
    if (negative)
        number *= -1;
    if (ch == '\n')
        ungetc(ch, stdin);
    return number;
}
int main(void)
{
    register int num = 0;
    register int sum = 0;
    while (1)
    {
        num = fast_read();
        switch (num)
        {
        case 10001:
            fprintf(stderr, "status 10001: '\\n' occured, output\n");
            printf("%d\n", sum);
            sum = 0;
            break;
        case 10002:
            fprintf(stderr, "status 10002: EOF occured, exit\n");
            return 0;
            break;
        default:
            sum += num;
            break;
        }
    }
    return 0;
}