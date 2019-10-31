/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
extern "C" char *gets(char *);

typedef struct sdata
{
    char data;
    struct sdata *next;
} SNODE;

void setlink(SNODE *, char *), outlink(SNODE *);
int listlen(SNODE *);
SNODE *ziplist(SNODE *, SNODE *);
SNODE *findlist(SNODE *, SNODE *);

int main()
{
    SNODE *head1, *head2, *head;
    char str1[100], str2[100];

    gets(str1);
    gets(str2);

    head1 = (SNODE *)malloc(sizeof(SNODE));
    head2 = (SNODE *)malloc(sizeof(SNODE));
    head = (SNODE *)malloc(sizeof(SNODE));
    head->next = head1->next = head2->next = NULL;

    setlink(head1, str1);
    setlink(head2, str2);

    head->next = ziplist(head1, head2);

    head->next = findlist(head1, head2);
    outlink(head);
    return 0;
}

void setlink(SNODE *head, char *str)
{
    SNODE *p;

    while (*str != '\0')
    {
        p = (SNODE *)malloc(sizeof(SNODE));
        p->data = *str;
        p->next = NULL;
        str++;
        head->next = p;
        head = p;
    }
    return;
}

void outlink(SNODE *head)
{
    while (head->next != NULL)
    {
        printf("%c", head->next->data);
        head = head->next;
    }
    printf("\n");
    return;
}

int listlen(SNODE *head)
{
    int len = 0;
    while (head->next != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

SNODE *findlist(SNODE *head1, SNODE *head2)
{
    int m, n;
    SNODE *p1 = head1, *p2 = head2;

    m = listlen(head1);
    n = listlen(head2);
    while (m > n)
    {
        p1 = p1->next;
        m--;
    }
    while (m < n)
    {
        p2 = p2->next;
        n--;
    }

    while (p1->next != NULL && p1->next != p2->next)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1->next;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void freelist(SNODE *head)
{
    return; // do nothing~ haha
}
SNODE *ziplist(SNODE *head1, SNODE *head2)
{
    if (!head1->next || !head2->next)
    {
        return NULL;
    }

    int len1 = listlen(head1);
    int len2 = listlen(head2);
    SNODE *lis1 = head1->next;
    SNODE *lis2 = head2->next;
    SNODE *tmp1, *tmp2;
    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            lis1 = lis1->next;
        }
    }
    else
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            lis2 = lis2->next;
        }
    }
    while (lis1)
    {
        if (lis1->data == lis2->data)
        {
            tmp1 = lis1;
            tmp2 = lis2;
            while (tmp1 && tmp1->data == tmp2->data)
            {
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            if (!tmp1)
            {
                tmp2 = head2;
                while (tmp2)
                {
                    if (tmp2->next == lis2)
                    {
                        freelist(tmp2);
                        tmp2->next = lis1;
                    }
                    tmp2 = tmp2->next;
                }
                return lis1;
            }
        }
        lis1 = lis1->next;
        lis2 = lis2->next;
    }
    return NULL;
}
