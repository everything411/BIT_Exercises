#include <iostream>
#include <stack>
#define MAXN 100100
using namespace std;
int in[MAXN];
int out[MAXN];
int main(int argc, char const *argv[])
{
    int n, m;
    stack<int> s;
    int cnt = 0;
    for (int i = 0; i < MAXN; i++)
    {
        in[i] = i + 1;
    }
    while (~scanf("%d%d", &n, &m) && (n || m))
    {
        if (cnt)
        {
            putchar('\n');
        }

        for (int i = 0; i < m; i++)
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%d", out + i);
            }
            int posin, posout;
            posin = posout = 0;
            while (posout < n)
            {
                if (in[posin] == out[posout])
                {
                    posin++;
                    posout++;
                }
                else if (!s.empty() && s.top() == out[posout])
                {
                    s.pop();
                    posout++;
                }
                else if (posin < n)
                {
                    s.push(in[posin++]);
                }
                else
                {
                    break;
                }
            }
            if (s.empty())
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
            cnt++;
            while (!s.empty())
            {
                s.pop();
            }
        }
    }

    return 0;
}
