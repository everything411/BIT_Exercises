#include <stdio.h>
int divide(int m, int n);
int main(int argc, char const *argv[])
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", divide(m, n));
    return 0;
}

int divide(int m, int n)
{
    if (n == 1 || m == 1)
        return 1;
    if (m > n)
        return divide(m, n - 1) + divide(m - n, n);
    if (m == n)
        return 1 + divide(m, n - 1);
    if (m < n)
        return divide(m, m);
}
