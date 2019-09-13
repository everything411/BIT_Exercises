#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
int main(void)
{
    char ch;
    queue<char> Q;
    stack<char> S;
    while ((ch = getchar()) != '\n')
    {
        Q.push(ch);
        S.push(ch);
    }
    while (!Q.empty())
    {
        if (Q.front() != S.top())
        {
            puts("不是回文");
            return 0;
        }
        else
        {
            Q.pop();
            S.pop();
        }
    }
    puts("是回文");
    return 0;
}