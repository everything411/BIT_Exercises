#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int compare(const void *, const void *);
int main(int argc, char const *argv[])
{
    int num[512] = {0};
    char buf[10240];
    int count = 0;
    int ans, a, b;
    char op;
    char *pos = buf;
    fgets(buf, 10240, stdin);
    while (isdigit(*pos) || isdigit(*(pos + 1)))
    {
        num[count++] = strtol(pos, &pos, 0);
        pos++;
    }
    op = *pos;
    qsort(num, count, sizeof(unsigned int), compare);
    a = num[0];
    b = num[count - 1];
    if (b == 0 && (op == '/' || op == '%'))
    {
        puts("Error!");
        return 1;
    }

    switch (op)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    case '%':
        ans = a % b;
        break;
    }
    printf(a < 0 ? "(%d) " : "%d ", a);
    putchar(op);
    printf(b < 0 ? " (%d)" : " %d", b);
    printf(" = %d\n", ans);
    return 0;
}
int compare(const void *i, const void *j)
{
    return *((const int *)i) < *((const int *)j) ? 1 : -1;
}