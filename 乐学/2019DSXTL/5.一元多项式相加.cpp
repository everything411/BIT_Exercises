#include <iostream>
#include <cstdlib>
using namespace std;
struct node_t
{
    int coef;
    int expn;
    node_t *next;
};

class Polynomial
{
private:
    node_t *head = NULL;
    int m;

public:
    node_t *GetHead()
    {
        return head;
    }
    bool IsEmpty()
    {
        return head->next == NULL;
    }
    void CreatePolyn()
    {
        if (!IsEmpty())
        {
            return;
        }
        scanf("%d", &m);
        node_t *curr = head;
        for (int i = 0; i < m; i++)
        {
            node_t *n = (node_t *)calloc(1, sizeof(node_t));
            scanf("%d%d", &n->coef, &n->expn);
            curr->next = n;
            curr = curr->next;
        }
    }
    void DestoryPolyn()
    {
        node_t *a = head->next;
        node_t *b;
        while (a)
        {
            b = a->next;
            free(a);
            a = b;
        }
        head->next = NULL;
        // free(head);
    }
    void PrintPolyn()
    {
        if (IsEmpty())
        {
            printf("<0,0>\n");
            return;
        }
        node_t *a;
        a = head->next;
        while (a)
        {
            if (a->next)
            {
                printf("<%d,%d>,", a->coef, a->expn);
            }
            else
            {
                printf("<%d,%d>\n", a->coef, a->expn);
            }
            a = a->next;
        }
    }
    void AddPolyn(Polynomial &b)
    {
        if (b.IsEmpty())
        {
            return;
        }

        node_t *ha = this->GetHead();
        node_t *hb = b.GetHead();
        node_t *qa, *qb;
        qa = ha->next;
        qb = hb->next;
        while (qa && qb)
        {
            int cmp = qa->expn - qb->expn;
            if (cmp == 0)
            {
                int sum = qa->coef + qb->coef;
                if (sum)
                {
                    qa->coef = sum;
                    ha = qa;
                    qa = qa->next;
                }
                else
                {
                    node_t *tmp;
                    tmp = qa;
                    ha->next = qa = qa->next;
                    free(tmp);
                }
                qb = qb->next;
            }
            else if (cmp > 0)
            {
                node_t *tmp;
                tmp = (node_t *)malloc(sizeof(node_t));
                *tmp = *qb;
                tmp->next = qa;
                ha->next = tmp;
                ha = qa;
                qa = qa->next;
                qb = qb->next;
            }
            else
            {
                ha = qa;
                qa = qa->next;
            }
        }
        if (qb != NULL)
        {
            node_t *tmp;
            while (qb)
            {
                tmp = (node_t *)malloc(sizeof(node_t));
                *tmp = *qb;
                tmp->next = NULL;
                ha->next = tmp;
                ha = ha->next;
                qb = qb->next;
            }
        }
    }
    Polynomial()
    {
        head = (node_t *)calloc(1, sizeof(node_t));
    }
    ~Polynomial()
    {
        // DestoryPolyn();
        free(head);
    }
};

int main(int argc, char const *argv[])
{
    int cmd;
    Polynomial a, b, c;
    while (~scanf("%d", &cmd))
    {
        if (cmd)
        {
            a.CreatePolyn();
            b.CreatePolyn();
            c.CreatePolyn();
            a.PrintPolyn();
            b.PrintPolyn();
            c.PrintPolyn();
            a.AddPolyn(b);
            a.PrintPolyn();
            a.AddPolyn(c);
            a.PrintPolyn();
            a.DestoryPolyn();
            b.DestoryPolyn();
            c.DestoryPolyn();
        }
        else
        {
            break;
        }
    }

    return 0;
}
