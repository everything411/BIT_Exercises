#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void swap(int &a, int &b)
{
    int i = a;
    a = b;
    b = i;
}
int sel_k(int *n, int len, int k)
{
    srand(time(0));
    int l = 0;
    int r = len - 1;
    while (l < r)
    {
        swap(n[l], n[rand() % (r - l + 1) + l]);
        int m = l;
        for (int i = l + 1; i <= r; i++)
        {
            if (n[i] < n[l])
            {
                swap(n[++m], n[i]);
            }
        }
        swap(n[l], n[m]);
        if (k <= m)
        {
            r = m - 1;
        }
        if (k >= m)
        {
            l = m + 1;
        }
    }
    return n[k];
}
#define MAXN 2000010
int y[MAXN];
int main(int argc, char const *argv[])
{
    int cnt = 0;
    while (scanf("%*d,%d", y + cnt) != EOF)
    {
        cnt++;
    }
    int m;
    if (cnt & 1)
    {
        m = cnt / 2;
    }
    else
    {
        m = cnt / 2 - 1;
    }
    int mid = sel_k(y, cnt, m);
    printf("%d\n", mid);
    return 0;
}
