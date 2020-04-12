/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

PNODE constructlist(PNODE head, int num);
void outlist(PNODE head);
void deleteneg(PNODE head);

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
            constructlist(head, num);
    }
    deleteneg(head);
    outlist(head);
    return 0;
}

PNODE constructlist(PNODE head, int num)
{
    PNODE p;
    p = (PNODE)malloc(sizeof(NODE));
    p->data = num;
    p->next = head->next;
    head->next = p;
    return head;
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
void deleteneg(PNODE head)
{
    _Bool free_node_flag = 0;
    PNODE current = head;
    PNODE prev, free_node_tmp;
    while (current->next)
    {
        if (free_node_flag)
        {
            free_node_tmp = current;
            current = current->next;
            free(free_node_tmp);
            free_node_flag = 0;
        }
        else
        {
            prev = current;
            current = current->next;
        }
        if (current->data < 0)
        {
            prev->next = current->next;
            free_node_flag = 1;
        }
    }
}