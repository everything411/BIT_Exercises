#include <iostream>
#define MAXN 1010
using namespace std;
int tree[MAXN];
int log2int(unsigned int i)
{
    int ans = 0;
    while (i)
    {
        ans++;
        i >>= 1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", tree + i);
    }
    int row, col;
    scanf("%d%d", &row, &col);
    if (!tree[row])
    {
        printf("ERROR: T[%d] is NULL\n", row);
        return 0;
    }
    if (!tree[col])
    {
        printf("ERROR: T[%d] is NULL\n", col);
        return 0;
    }
    int idrow, idcol;
    idrow = row;
    idcol = col;
    int logrow = log2int(idrow);
    int logcol = log2int(idcol);
    if (logrow > logcol)
    {
        idrow >>= logrow - logcol;
    }
    else if (logrow < logcol)
    {
        idcol >>= logcol - logrow;
    }
    while (idrow != idcol)
    {
        idrow >>= 1;
        idcol >>= 1;
    }
    printf("%d %d\n", idrow, tree[idrow]);
    return 0;
}
