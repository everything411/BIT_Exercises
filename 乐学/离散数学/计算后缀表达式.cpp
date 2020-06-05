#include <iostream>
#include <cctype>
int s[10000];
int p = 0;
bool empty()
{
    return p == 0;
}
int pop()
{
    return s[--p];
}
void push(int c)
{
    s[p++] = c;
}
int calc(int x, char ch, int y)
{
    switch (ch)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return 0;
        break;
    }
}
int main(int argc, char const *argv[])
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            goto die;
        }
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            if (empty())
            {
                goto die;
            }
            else
            {
                int y = pop();
                int x = pop();
                if (ch == '/' && y == 0)
                {
                    goto divzero;
                }
                push(calc(x, ch, y));
            }
        }
    }
    if (p != 1)
    {
        goto die;
    }
    printf("%d\n", pop());
    if (false)
    {
    die:
        puts("ERROR!");
    }
    if (false)
    {
    divzero:
        puts("DIV0!");
    }

    return 0;
}
