#include <iostream>
#include <cstdlib>
#include <cassert>
#define EQ(Elem1, Elem2) ((Elem1) == (Elem2))
#define LT(Elem1, Elem2) ((Elem1) < (Elem2))
#define LH 0
#define EH 1
#define RH 2
using namespace std;
struct ElemType
{
    char key;
};
struct BSTNode
{
    ElemType data;
    int bf;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
};
typedef struct BSTNode *BSTree;
void PreOrderTraverse(BSTree T)
{
    if (T)
    {
        putchar(T->data.key);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BSTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        putchar(T->data.key);
        InOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BSTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        putchar(T->data.key);
    }
}
void R_Rotate(BSTree &p)
{
    BSTree lc;
    lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
}
void L_Rotate(BSTree &p)
{
    BSTree rc;
    rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}

void LeftBalance(BSTree &T)
{
    BSTree lc, rd;
    lc = T->lchild;
    switch (lc->bf)
    {
    case LH:
        T->bf = lc->bf = EH;
        R_Rotate(T);
        break;
    case RH:
        rd = lc->rchild;
        switch (rd->bf)
        {
        case LH:
            T->bf = RH;
            lc->bf = EH;
            break;
        case EH:
            T->bf = lc->bf = EH;
            break;
        case RH:
            T->bf = EH;
            lc->bf = LH;
            break;
        }
        rd->bf = EH;
        L_Rotate(T->lchild);
        R_Rotate(T);
    }
}
void RightBalance(BSTree &T)
{
    BSTree rc, ld;
    rc = T->rchild;
    switch (rc->bf)
    {
    case RH:
        T->bf = rc->bf = EH;
        L_Rotate(T);
        break;
    case LH:
        ld = rc->lchild;
        switch (ld->bf)
        {
        case RH:
            T->bf = LH;
            rc->bf = EH;
            break;
        case EH:
            T->bf = rc->bf = EH;
            break;
        case LH:
            T->bf = EH;
            rc->bf = RH;
            break;
        }
        ld->bf = EH;
        R_Rotate(T->rchild);
        L_Rotate(T);
    }
}
static bool taller = false;
bool InsertAVL(BSTree &T, const ElemType e)
{
    if (!T)
    {
        T = (BSTree)calloc(1, sizeof(BSTNode));
        T->data = e;
        T->lchild = T->rchild = NULL;
        T->bf = EH;
        taller = true;
    }
    else
    {
        if (EQ(e.key, T->data.key))
        {
            taller = false;
            return false;
        }
        if (LT(e.key, T->data.key))
        {
            if (!InsertAVL(T->lchild, e))
            {
                return false;
            }
            if (taller)
            {
                switch (T->bf)
                {
                case LH:
                    LeftBalance(T);
                    taller = false;
                    break;
                case EH:
                    T->bf = LH;
                    taller = true;
                    break;
                case RH:
                    T->bf = EH;
                    taller = false;
                    break;
                }
            }
        }
        else
        {
            if (!InsertAVL(T->rchild, e))
            {
                return false;
            }
            if (taller)
                switch (T->bf)
                {
                case LH:
                    T->bf = EH;
                    taller = false;
                    break;
                case EH:
                    T->bf = RH;
                    taller = true;
                    break;
                case RH:
                    RightBalance(T);
                    taller = false;
                    break;
                }
        }
    }
    return true;
}
void PrintAVLTree(BSTree t, int depth)
{
    if (t)
    {
        if (t->rchild)
        {
            PrintAVLTree(t->rchild, depth + 1);
        }
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("%c\n", t->data.key);
        if (t->lchild)
        {
            PrintAVLTree(t->lchild, depth + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    struct ElemType e;
    BSTree t = NULL;
    while ((e.key = getchar()) != '\n')
    {
        InsertAVL(t, e);
    }
    printf("Preorder: ");
    PreOrderTraverse(t);
    printf("\nInorder: ");
    InOrderTraverse(t);
    printf("\nPostorder: ");
    PostOrderTraverse(t);
    printf("\nTree:\n");
    PrintAVLTree(t, 0);
    return 0;
}
