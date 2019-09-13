#include <iostream>
#include <cstdlib>
using namespace std;
struct node_t
{
    int number;
    node_t *next;
};
void insert(int num, node_t *head)
{
    while (head->next)
    {
        head = head->next;
    }
    head->next = (node_t *)calloc(1, sizeof(node_t));
    head->next->number = num;
}
int del(int num, node_t *head)
{
    node_t *prev_node = head;
    node_t *pprev_node = NULL;
    head = head->next;
    while (head && head->next)
    {
        if (head->number == num)
        {
            if (pprev_node == NULL)
            {
                return -1;
            }
            pprev_node->next = head;
            free(prev_node);
            return 1;
        }
        pprev_node = prev_node;
        prev_node = head;
        head = head->next;
    }
    return 0;
}
void print(node_t *head)
{
    while ((head = head->next))
    {
        if (head->next)
        {
            printf("%d ", head->number);
        }
        else
        {
            printf("%d\n", head->number);
        }
    }
}
int main(void)
{
    node_t *head = (node_t *)calloc(1, sizeof(node_t));
    node_t *curr = head;
    node_t *prev_node = head;
    int number;
    while (cin >> number)
    {
        insert(number, head);
    }
    while (curr->next)
    {
        prev_node = curr;
        curr = curr->next;
    }
    prev_node->next = NULL;
    free(curr);
    if (del(number, head) == -1)
    {
        puts("该结点没有前驱结点");
    }
    else
    {
        print(head);
    }
    return 0;
}