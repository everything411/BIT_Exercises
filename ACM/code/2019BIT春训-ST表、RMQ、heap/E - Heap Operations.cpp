//See https://www.cnblogs.com/scaugsh/p/5586633.html
#include <iostream>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
char ans[1000010][64];
int main(int argc, char const *argv[])
{
    priority_queue<int, vector<int>, greater<int>> my_heap;
    char cmd[10];
    int num;
    int n;
    int pos = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", cmd, &num);
        if (strcmp(cmd, "insert") == 0)
        {
            my_heap.push(num);
            sprintf(ans[pos++], "insert %d", num);
        }
        else if (strcmp(cmd, "getMin") == 0)
        {
            if (my_heap.empty())
            {
                sprintf(ans[pos++], "insert %d", num);
                my_heap.push(num);
            }
            else if (num != my_heap.top())
            {
                while (!my_heap.empty() && num > my_heap.top())
                {
                    sprintf(ans[pos++], "removeMin");
                    my_heap.pop();
                }
                if (my_heap.empty() || my_heap.top() != num)
                {
                    my_heap.push(num);
                    sprintf(ans[pos++], "insert %d", num);
                }
            }
            sprintf(ans[pos++], "getMin %d", num);
        }
        else
        {
            if (!my_heap.empty())
            {
                my_heap.pop();
                sprintf(ans[pos++], "removeMin");
            }
            else
            {
                sprintf(ans[pos++], "insert 0");
                sprintf(ans[pos++], "removeMin");
            }
        }
    }
    printf("%d\n", pos);
    for (int i = 0; i < pos; i++)
        printf("%s\n", ans[i]);
    return 0;
}
