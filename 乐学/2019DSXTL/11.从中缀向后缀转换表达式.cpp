#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int isp[128];
int icp[128];
void init()
{
    isp['#'] = icp['#'] = 0;
    isp['('] = 1;
    icp['('] = 8;
    isp['^'] = 6;
    icp['^'] = 7;
    isp['*'] = isp['%'] = isp['/'] = 5;
    icp['*'] = icp['%'] = icp['/'] = 4;
    isp['+'] = isp['-'] = 3;
    icp['+'] = icp['-'] = 2;
    isp[')'] = 8;
    icp[')'] = 1;
}
struct operand
{
    bool is_int;
    int val;
    void print()
    {
        printf(is_int ? "%d" : "%c", val);
        fflush(stdout);
    }
};
char getoperator()
{
    return getchar();
}
void getoperand(struct operand &o)
{
    char ch;
    int val = 0;
    bool is_nega = false;
    ch = getchar();
    if (isalpha(ch))
    {
        o.is_int = false;
        o.val = ch;
        return;
    }
    else if (ch == '-')
    {
        is_nega = true;
    }
    else
    {
        ungetc(ch, stdin);
    }
    while (isdigit(ch = getchar()))
    {
        val *= 10;
        val += ch - '0';
    }
    ungetc(ch, stdin);
    if (is_nega)
    {
        val = -val;
    }
    o.is_int = true;
    o.val = val;
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    stack<char> s;
    struct operand operand;
    scanf("%d", &t);
    getchar(); // '\n'
    for (int i = 0; i < t; i++)
    {
        s.push('#');
        char ch, chprev;
        chprev = '#';
        while (true)
        {
            ch = getoperator();
            if (isalnum(ch))
            {
            do_operand:
                ungetc(ch, stdin);
                getoperand(operand);
                operand.print();
            }
            else
            {
                if (ch == '-')
                {
                    if (!isalnum(chprev) && chprev != ')')
                    {
                        goto do_operand;
                    }
                }
                if (ch == '(')
                {
                    s.push(ch);
                }
                else if (ch == ')')
                {
                    while (s.top() != '(')
                    {
                        putchar(s.top());
                        s.pop();
                    }
                    s.pop();
                }
                else if (icp[ch] > isp[s.top()])
                {
                    s.push(ch);
                }
                else
                {
                    while (icp[ch] < isp[s.top()])
                    {
                        putchar(s.top());
                        s.pop();
                    }
                    s.push(ch);
                }
            }
            if (ch == '#')
            {
                while (!s.empty())
                {
                    if (s.top() != '#')
                    {
                        putchar(s.top());
                    }
                    s.pop();
                }
                putchar(getchar()); // '\n'
                break;
            }
            chprev = ch;
        }
    }
    return 0;
}
