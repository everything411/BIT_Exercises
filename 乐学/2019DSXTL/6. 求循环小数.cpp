/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void output(NODE *, int);
void change(int, int, NODE *);

void output(NODE *head, int kk)
{
    int k = 0;

    printf("0.");
    while (head->next != NULL && k < kk)
    {
        printf("%d", head->next->data);
        head = head->next;
        k++;
    }
    printf("\n");
}

int main()
{
    int n, m, k;
    NODE *head;

    scanf("%d%d%d", &n, &m, &k);
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;
    change(n, m, head);
    output(head, k);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

#define MAX_DIGIT 20480
typedef NODE node_t;
typedef NODE *p_node_t;
p_node_t loop_head;

int search_history(int _remainder, int *history_remainder)
{
    for (int i = 0; history_remainder[i]; i++)
        if (_remainder == history_remainder[i])
        {
            fprintf(stderr, "search_history() has found the remainder at index %d.\n", i);
            return i;
        }
    return -1;
}
void change(int numerator, int denominator, p_node_t head)
{
    int history_index;
    int _remainder;
    p_node_t p;
    p_node_t current = head;
    int *history_remainder = (int *)calloc(MAX_DIGIT, sizeof(int));
    for (int i = 0; numerator; i++)
    {
        p = (p_node_t)calloc(1, sizeof(node_t));
        p->data = numerator * 10 / denominator;
        _remainder = numerator * 10;
        numerator = _remainder % denominator;
        if ((history_index = search_history(_remainder, history_remainder)) != -1)
        {
            loop_head = head->next;
            for (int i = 0; i < history_index; i++)
                loop_head = loop_head->next;
            current->next = loop_head;
            return;
        }
        history_remainder[i] = _remainder;
        current = (current->next = p);
    }
    // // Only when there is no loop, will these two lines be executed.
    // printf("ring=0\nNULL\n");
    // exit(1);
}

p_node_t find(p_node_t head, int *length)
{
    // Use a global variable to store the head of the loop list
    // This may be the fastest way to "find" it
    // Since the head node is of no use, I reuse it as a temp variable
    head = loop_head->next;
    for (*length = 1; head != loop_head; (*length)++)
        head = head->next;
    return loop_head;
}