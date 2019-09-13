#include <iostream>
#include <stack>
using namespace std;
stack<int> stone_stack;
int main(void)
{
    int n;
    int height;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &height);
            if (!stone_stack.empty())
            {
                if ((stone_stack.top() & 1) == (height & 1))
                {
                    stone_stack.pop();
                }
                else
                {
                    stone_stack.push(height);
                }
            }
            else
            {
                stone_stack.push(height);
            }
        }
        // cout << stone_stack.size() << endl;
        if (stone_stack.size() == 0 || stone_stack.size() == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        while (!stone_stack.empty())
        {
            stone_stack.pop();
        }
    }
    return 0;
}