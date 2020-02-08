#include <iostream>
#define MAXN 100
using namespace std;
struct MatrixElement
{
    int i;
    int j;
    int elem;
};
struct TSMatrix
{
    int row;
    int col;
    int nonzero;
    MatrixElement data[MAXN];
};
void FastTransposeSMatrix(TSMatrix &M, TSMatrix &T);
TSMatrix M, T;
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &M.row, &M.col, &M.nonzero);
    for (int i = 1; i <= M.nonzero; i++)
    {
        scanf("%d%d%d", &M.data[i].i, &M.data[i].j, &M.data[i].elem);
    }
    FastTransposeSMatrix(M, T);
    return 0;
}
void FastTransposeSMatrix(TSMatrix &M, TSMatrix &T)
{
    static int colm[MAXN], cpot[MAXN];
    T.row = M.col;
    T.col = M.row;
    T.nonzero = M.nonzero;
    if (T.nonzero)
    {
        for (int i = 1; i <= M.col; i++)
        {
            colm[i] = 0;
        }
        for (int i = 1; i <= M.nonzero; i++)
        {
            colm[M.data[i].j]++;
        }
        cpot[1] = 1;
        for (int i = 2; i <= M.col; i++)
        {
            cpot[i] = cpot[i - 1] + colm[i - 1];
        }
        printf("num:");
        for (int i = 1; i <= M.col; i++)
        {
            printf("%d,", colm[i]);
        }
        printf("\ncpot:");
        for (int i = 1; i <= M.col; i++)
        {
            printf("%d,", cpot[i]);
        }
        printf("\n");
        int col, q;
        for (int p = 1; p <= M.nonzero; p++)
        {
            col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].elem = M.data[p].elem;
            ++cpot[col];
        }
    }
    for (int i = 1; i <= T.nonzero; i++)
    {
        printf("%d,%d,%d\n", T.data[i].i, T.data[i].j, T.data[i].elem);
    }
}
