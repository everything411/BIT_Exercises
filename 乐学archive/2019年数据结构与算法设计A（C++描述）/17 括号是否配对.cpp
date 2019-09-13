#include <iostream>
using namespace std;
char stack[5000];
int pos;
char pop(void)
{
    return pos != 0 ? stack[--pos] : EOF;
}
void push(char ch)
{
    stack[pos++] = ch;
}
int match(char left, char right)
{
    return (left == '{' && right == '}') || (left == '[' && right == ']') || (left == '(' && right == ')');
}
int main(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case '{':
            push('{');
            break;
        case '[':
            push('[');
            break;
        case '(':
            push('(');
            break;
        case '}':
            if ((ch = pop()) == EOF || !match(ch, '}'))
            {
                puts("括号不配对");
                return 0;
            }

            break;
        case ']':
            if ((ch = pop()) == EOF || !match(ch, ']'))
            {
                puts("括号不配对");
                return 0;
            }
            break;
        case ')':
            if ((ch = pop()) == EOF || !match(ch, ')'))
            {
                puts("括号不配对");
                return 0;
            }
            break;
        default:
            break;
        }
    }
    puts("括号配对");
    return 0;
}