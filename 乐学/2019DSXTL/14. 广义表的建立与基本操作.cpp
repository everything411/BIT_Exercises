#include <iostream>
#include <cstring>
#define ATOM 1
#define LIST 2
using namespace std;
typedef char Element;
struct GLNode
{
    int tag;
    union {
        struct
        {
            GLNode *hp;
            GLNode *tp;
        } ptr;
        Element atom;
    };
};
typedef GLNode *GList;

void sever(char *sub, char *hsub)
{
    int n = strlen(sub);
    int i = 0, k = 0;
    char ch;
    do
    {
        i++;
        ch = sub[i - 1];
        if (ch == '(')
        {
            k++;
        }
        else if (ch == ')')
        {
            k--;
        }

    } while (i < n && (ch != ',' || k != 0));
    if (i < n)
    {
        memmove(hsub, sub, i - 1);
        hsub[i - 1] = 0;
        memmove(sub, sub + i, n - i);
        sub[n - i] = 0;
    }
    else
    {
        strcpy(hsub, sub);
        sub[0] = 0;
    }
}
void CreateGList(GList &L, char *S)
{
    char sub[1000], hsub[1000];
    GList p, q;
    if (strcmp(S, "()") == 0)
    {
        L = NULL;
    }
    else
    {
        L = (GList)malloc(sizeof(GLNode));
        if (!L)
        {
            return;
        }
        if (strlen(S) == 1)
        {
            L->tag = ATOM;
            L->atom = S[0];
        }
        else
        {
            L->tag = LIST;
            p = L;
            int len = strlen(S + 1) - 1;
            memmove(sub, S + 1, len);
            sub[len] = 0;
            do
            {
                sever(sub, hsub);
                CreateGList(p->ptr.hp, hsub);
                q = p;
                if (sub[0] != 0)
                {
                    if (!(p = (GLNode *)malloc(sizeof(GLNode))))
                        return;
                    p->tag = LIST;
                    q->ptr.tp = p;
                }
            } while (sub[0] != 0);
            q->ptr.tp = NULL;
        }
    }
}
GList GetHead(GList L)
{
    if (L != NULL)
    {
        return L->ptr.hp;
    }
    else
    {
        return NULL;
    }
}
GList GetTail(GList L)
{
    if (L != NULL)
    {
        return L->ptr.tp;
    }
    else
    {
        return NULL;
    }
}
void DestroyGList(GList &L)
{
    fputs("DestroyGList(): not implemented.\n", stderr);
    return;
}
void do_print(GList L)
{
    if (L->ptr.hp != NULL)
    {
        if (L->ptr.hp->tag == ATOM)
        {
            printf("%c", L->ptr.hp->atom);
        }
        else
        {
            putchar('(');
            do_print(L->ptr.hp);
            putchar(')');
        }
    }
    else
    {
        printf("()");
    }
    if (L->ptr.tp != NULL)
    {
        printf(",");
        do_print(L->ptr.tp);
    }
}
void PrintGList(GList L)
{
    printf("generic list: ");
    if (L != NULL)
    {
        if (L->tag == ATOM)
        {
            printf("%c", L->atom);
        }
        else
        {
            putchar('(');
            do_print(L);
            putchar(')');
        }
    }
    else
    {
        printf("()");
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    char str[1000];
    GList lis;
    int cmd;
    scanf("%s", str);
    CreateGList(lis, str);
    PrintGList(lis);
    while (~scanf("%d", &cmd))
    {
        if (cmd == 1)
        {
            GList head = GetHead(lis);
            GList tail = GetTail(lis);
            printf("destroy tail\nfree list node\n");
            DestroyGList(tail);
            lis = head;
            PrintGList(lis);
        }
        else if (cmd == 2)
        {
            GList head = GetHead(lis);
            GList tail = GetTail(lis);
            printf("free head node\nfree list node\n");
            DestroyGList(head);
            lis = tail;
            PrintGList(lis);
        }
        else
        {
            fputs("go die\n", stderr);
        }
    }

    return 0;
}

/*
int GListDepth(GList L)
{
    int max, dep;
    GList pp;
    if (!L)
        return 1;
    if (L->tag == ATOM)
        return 0;
    for (max = 0, pp = L; pp; pp = pp->ptr.tp)
    {
        dep = GListDepth(pp->ptr.hp); // 求以pp->ptr.hp为头指针的子表深度
        if (dep > max)
            max = dep;
    }
    return max + 1;
}

void CopyGList(GList &T, GList L)
{
    if (!L)
        T = NULL; // 复制空表
    else
    {
        if (!(T = (GList)malloc(sizeof(GLNode)))) // 建表结点
            return;                               // ERROR;
        T->tag = L->tag;
        if (L->tag == ATOM)
            T->atom = L->atom; // 复制单原子
        else
        {
            CopyGList(T->ptr.hp, L->ptr.hp);
            // 复制广义表T->ptr.hp的副本L->ptr.hp
            CopyGList(T->ptr.tp, L->ptr.tp);
            // 复制广义表T->ptr.tp的副本L->ptr.tp
        }
    }
    return;
}
*/
