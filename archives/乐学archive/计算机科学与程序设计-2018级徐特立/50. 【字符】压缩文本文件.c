#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 128
typedef struct word
{
    char value[LEN];
    int order;
    struct word *next;
} word_t;
void add(word_t *, char *, int);
int search(word_t *, char *);
int main(int argc, char const *argv[])
{
    char ch;
    int i;
    char temp_str[LEN];
    int order, count;
    count = 0;
    word_t *word_list = (word_t *)calloc(1, sizeof(word_t));
    while (1)
    {
        for (i = 0; isalpha(ch = getchar()); i++)
            temp_str[i] = ch;
        if (ch == EOF)
            break;
        temp_str[i] = '\0';
        if (i)
        {
            if ((order = search(word_list, temp_str)))
                printf("%d", order);
            else
            {
                add(word_list, temp_str, ++count);
                printf("%s", temp_str);
            }
        }
        putchar(ch);
    }
    return 0;
}

int search(word_t *word_list, char *str)
{
    while (word_list != NULL)
    {
        if (!strcmp(word_list->value, str))
        {
            fprintf(stderr, "\x1b[33msearch() :found string \"%s\" at order %d\n\x1b[0m", str, word_list->order);
            return word_list->order;
        }
        word_list = word_list->next;
    }
    return 0;
}
void add(word_t *word_list, char *str, int order)
{
    word_t **word_mem_addr;
    while (word_list != NULL)
    {
        word_mem_addr = &(word_list->next);
        word_list = word_list->next;
    }
    word_list = *word_mem_addr = (word_t *)calloc(1, sizeof(word_t));
    strncpy(word_list->value, str, LEN);
    word_list->order = order;
    word_list->next = NULL;

    fprintf(stderr, "\x1b[33madd() :add string \"%s\" at order %d\n\x1b[0m", str, order);

    return;
}