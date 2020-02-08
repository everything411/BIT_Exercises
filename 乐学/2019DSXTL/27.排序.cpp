#include <iostream>
using namespace std;
struct HeapType
{
    int *r;
    int length;
    HeapType(int n)
    {
        length = n;
        r = new int[length + 2];
    }
    ~HeapType()
    {
        delete[] r;
    }
    void AddElem(int n)
    {
        static int l = 1;
        r[l++] = n;
    }
};
void HeapAdjust(HeapType &H, int s, int m)
{
    int rc;
    rc = H.r[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && H.r[j] < H.r[j + 1])
        {
            ++j;
        }
        if (rc >= H.r[j])
        {
            break;
        }
        H.r[s] = H.r[j];
        s = j;
    }
    H.r[s] = rc;
}
void HeapSort(HeapType &H)
{
    for (int i = H.length / 2; i > 0; --i)
    {
        HeapAdjust(H, i, H.length);
    }
    for (int i = 1; i <= H.length; i++)
    {
        printf("%d ", H.r[i]);
    }
    putchar('\n');
    for (int i = H.length; i > 1; --i)
    {
        swap(H.r[1], H.r[i]);
        HeapAdjust(H, 1, i - 1);
        if (i == H.length)
        {
            for (int i = 1; i < H.length; i++)
            {
                printf("%d ", H.r[i]);
            }
            putchar('\n');
        }
        else if (i == H.length - 1)
        {
            for (int i = 1; i < H.length - 1; i++)
            {
                printf("%d ", H.r[i]);
            }
            putchar('\n');
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    HeapType h(n);
    for (int i = 0; i < h.length; i++)
    {
        scanf("%d", &n);
        h.AddElem(n);
    }
    HeapSort(h);
    return 0;
}
