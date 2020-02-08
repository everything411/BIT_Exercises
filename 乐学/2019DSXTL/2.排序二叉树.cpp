#include <iostream>
#include <cstdlib>
#define EQ(Elem1, Elem2) ((Elem1) == (Elem2))
#define LT(Elem1, Elem2) ((Elem1) < (Elem2))
using namespace std;
struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
};
typedef struct BiTNode *BiTree;
bool SearchBST(BiTree T, int key, BiTree f, BiTree &p)
{
    if (!T)
    {
        p = f;
        return false;
    }
    else if (EQ(key, T->data))
    {
        p = T;
        return true;
    }
    else if (LT(key, T->data))
    {
        return SearchBST(T->lchild, key, T, p);
    }
    else
    {
        return SearchBST(T->rchild, key, T, p);
    }
}

void InsertBST(BiTree &T, int e)
{
    BiTree p, s;
    if (!SearchBST(T, e, NULL, p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->rchild = NULL;
        if (!p)
        {
            T = s;
        }
        else if (LT(e, p->data))
        {
            p->lchild = s;
        }
        else
        {
            p->rchild = s;
        }
    }
}
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        printf(" %d", T->data);
        InOrderTraverse(T->rchild);
    }
}
void PrintBST(BiTree T, int blank)
{
    if (!T)
    {
        return;
    }
    PrintBST(T->lchild, blank + 1);
    for (int i = 0; i < blank * 4; i++)
    {
        putchar(' ');
    }
    printf("%d\n", T->data);
    PrintBST(T->rchild, blank + 1);
}
int main(int argc, char const *argv[])
{
    BiTree t = NULL;
    int num;
    while (~scanf("%d", &num) && num)
    {
        InsertBST(t, num);
    }
    PrintBST(t, 0);
    putchar('\n');
    InOrderTraverse(t);
    putchar('\n');
    return 0;
}
