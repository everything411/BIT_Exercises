#include <stdio.h>
inline int sum(int start, int end);
inline void swap(int *x, int *y);
int main(int argc, char const *argv[])
{
    int num1, num2;
    while (scanf("%d%d", &num1, &num2) && (num1 || num2))
        printf("%d\n", sum(num1, num2));
    puts("exit");
    return 0;
}
int sum(int start, int end)
{
    if (start > end)
        swap(&start, &end);
    int ans = 0;
    for (int i = start; i <= end; i++)
        ans += i;
    return ans;
}
void swap(int *x, int *y)
{
    if (x != y)
    {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}