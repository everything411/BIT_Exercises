#include <stdio.h>
#include <string.h>
void heapify(long long *, int);
void siftdown(long long *, int, int);
void swap(long long *a, long long *b);
long long canvas_size[200020];
long long ans;
int canvas_count;
void heapify(long long *priority_queue, int len)
{
    for (int i = (len - 1) / 2; i >= 0; i--)
    {
        siftdown(priority_queue, i, len);
    }
}
void siftdown(long long *priority_queue, int k, int len)
{
    int son;
    while (k * 2 + 1 < len)
    {
        son = k * 2 + 1; // priority_queue[i]'s left son
        if (k * 2 + 2 < len && priority_queue[son] > priority_queue[k * 2 + 2])
        {
            son = k * 2 + 2; // choose the smaller one
        }
        if (priority_queue[son] > priority_queue[k])
        {
            break;
        }
        swap(priority_queue + son, priority_queue + k);
        k = son;
    }
}
void swap(long long *a, long long *b)
{
    long long tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void)
{
    int t_count;
    scanf("%d", &t_count);
    for (int i = 0; i < t_count; i++)
    {
        scanf("%d", &canvas_count);
        memset(canvas_size, 0, sizeof(canvas_size));
        for (int i = 0; i < canvas_count; i++)
        {
            scanf("%lld", canvas_size + i);
        }
        if (canvas_count == 1) // bug check
        {
            puts("0");
            continue;
        }
        ans = 0;
        heapify(canvas_size, canvas_count);
        for (int i = canvas_count - 1; i > 1; i--)
        {
            if (canvas_size[1] < canvas_size[2])
            {
                ans += canvas_size[0] + canvas_size[1];
                canvas_size[1] += canvas_size[0];
                swap(canvas_size + 0, canvas_size + i);
                siftdown(canvas_size, 1, i);
                siftdown(canvas_size, 0, i);
            }
            else
            {
                ans += canvas_size[0] + canvas_size[2];
                canvas_size[2] += canvas_size[0];
                swap(canvas_size + 0, canvas_size + i);
                siftdown(canvas_size, 2, i);
                siftdown(canvas_size, 0, i);
            }
        }
        ans += canvas_size[0] + canvas_size[1];
        printf("%lld\n", ans);
    }

    return 0;
}