#include <iostream>
#include <stack>
using namespace std;
stack<int> stone_stack;
int main(void)
{
    int n;
    int height;
    int highest;
    while (~scanf("%d", &n))
    {
        highest = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &height);
            highest = max(highest, height);
            if (!stone_stack.empty())
            {
                if (stone_stack.top() < height)
                {
                    scanf("%*[^\n]");
                    goto fail;
                }
                if (stone_stack.top() == height)
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
        if (stone_stack.size() == 0)
        {
            puts("YES");
        }
        else if (stone_stack.size() == 1)
        {
            if (stone_stack.top() != highest)
            {
                puts("NO");
            }
            else
            {
                puts("YES");
            }
        }
        else
        {
        fail:
            puts("NO");
        }
        while (!stone_stack.empty())
        {
            stone_stack.pop();
        }
    }
    return 0;
}