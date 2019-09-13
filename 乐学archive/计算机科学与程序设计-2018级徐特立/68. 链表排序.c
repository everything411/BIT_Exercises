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
void outlist(PNODE);
int sortlist(PNODE h, int num);
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
            sortlist(head, num);
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

int sortlist(PNODE head, int num)
{
    PNODE node, curr, prev;
    node = (PNODE)calloc(1, sizeof(NODE));
    node->data = num;
    curr = head;
    while (curr && curr->data < num)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->data == num)
    {
        free(node);
        return 1;
    }
    else
    {
        prev->next = node;
        node->next = curr;
        return 0;
    }
}