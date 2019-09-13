#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, ans;
    char ch;
    scanf("%d%c%d", &a, &ch, &b);
    switch (ch)
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
    printf("%d\n", ans);
    return 0;
}
