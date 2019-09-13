#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
enum
{
    PUSH = 1,
    POP = 2
};
stack<int> Stack;
queue<int> Queue;
priority_queue<int, vector<int>, greater<int>> Small_priqueue;
priority_queue<int, vector<int>, less<int>> Big_priqueue;
bool is_stack, is_queue, is_small_pri, is_big_pri;
void output_ans(void)
{
    int count = is_stack + is_queue + is_small_pri + is_big_pri;
    switch (count)
    {
    case 0:
        puts("pool zls");
        break;
    case 1:
        if (is_stack)
        {
            puts("stack");
        }
        else if (is_queue)
        {
            puts("queue");
        }
        else if (is_small_pri)
        {
            puts("small priority queue");
        }
        else if (is_big_pri)
        {
            puts("big priority queue");
        }
        break;
    default:
        puts("not sure");
        break;
    }
}
void empty_all(void)
{
    while (!Stack.empty())
    {
        Stack.pop();
    }
    while (!Queue.empty())
    {
        Queue.pop();
    }
    while (!Small_priqueue.empty())
    {
        Small_priqueue.pop();
    }
    while (!Big_priqueue.empty())
    {
        Big_priqueue.pop();
    }
}
int main(void)
{
    int n;
    int op;
    int number;
    while (~scanf("%d", &n))
    {
        is_stack = is_queue = is_small_pri = is_big_pri = true;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &op, &number);
            switch (op)
            {
            case PUSH:
                if (is_stack)
                {
                    Stack.push(number);
                }
                if (is_queue)
                {
                    Queue.push(number);
                }
                if (is_big_pri)
                {
                    Big_priqueue.push(number);
                }
                if (is_small_pri)
                {
                    Small_priqueue.push(number);
                }
                break;
            case POP:
                if (is_stack)
                {
                    if (number != Stack.top())
                    {
                        is_stack = false;
                    }
                    Stack.pop();
                }
                if (is_queue)
                {
                    if (number != Queue.front())
                    {
                        is_queue = false;
                    }
                    Queue.pop();
                }
                if (is_big_pri)
                {
                    if (number != Big_priqueue.top())
                    {
                        is_big_pri = false;
                    }
                    Big_priqueue.pop();
                }
                if (is_small_pri)
                {
                    if (number != Small_priqueue.top())
                    {
                        is_small_pri = false;
                    }
                    Small_priqueue.pop();
                }
                break;
            default:
                fputs("go die!\n", stderr);
                break;
            }
        }
        output_ans();
        empty_all();
    }
    return 0;
}