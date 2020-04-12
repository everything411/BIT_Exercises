/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
int ins_list(PNODE head, int num);
void outlist(PNODE);

int main()
{
    int num = 1;
    PNODE head;

    head = (PNODE)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;

    while (num != 0)
    {
        scanf("%d", &num);
        if (num != 0)
            ins_list(head, num);
    }

    outlist(head);
    return 0;
}

void outlist(PNODE head)
{
    PNODE p;
    p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */

int ins_list(PNODE head, int num)
{
    while (head->next)
        head = head->next;
    head->next = (PNODE)calloc(1, sizeof(NODE));
    head->next->data = num;
    return 0;
}
