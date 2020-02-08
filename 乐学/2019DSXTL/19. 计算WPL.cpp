#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct HTNode
{
    int weight;
    int parent;
    int lchild;
    int rchild;
};
typedef struct HTNode *HuffmanTree;
void Select(HuffmanTree t, int len, int &s1, int &s2)
{
    int wei1, wei2;
    wei1 = wei2 = 0x3f3f3f3f;
    for (int i = 1; i <= len; i++)
    {
        if (!t[i].parent)
        {
            if (t[i].weight < wei1)
            {
                wei2 = wei1;
                s2 = s1;
                wei1 = t[i].weight;
                s1 = i;
            }
            else if (t[i].weight < wei2)
            {
                wei2 = t[i].weight;
                s2 = i;
            }
        }
    }
}
int HuffmanCoding(HuffmanTree &HT, int *w, int n)
{
    int m, s1, s2;
    if (n <= 1)
        return 0;
    m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for (int i = 1; i <= n; i++)
    {
        HT[i].weight = w[i - 1];
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (int i = n + 1; i <= m; i++)
    {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (int i = n + 1; i <= m; i++)
    {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    int s = 0;
    for (int i = 1; i < m; i++)
    {
        s += HT[i].weight;
    }
    return s;
}
int weight[100];
int main(int argc, char const *argv[])
{
    HuffmanTree t;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    int wpl = HuffmanCoding(t, weight, n);
    printf("WPL=%d\n", wpl);
    free(t);
    return 0;
}
