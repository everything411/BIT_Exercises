#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 128
typedef struct word
{
    char value[LEN];
    int count;
    struct word *next;
} word_t;
void add(word_t *, char *);
int search(word_t *, char *);
void print(word_t *);
int main(int argc, char const *argv[])
{
    char ch;
    int i;
    char temp_str[LEN];
    word_t *word_list = (word_t *)calloc(1, sizeof(word_t));
    while (1)
    {
        for (i = 0; isalpha(ch = getchar()); i++)
            temp_str[i] = ch;
        if (ch == EOF)
            break;
        temp_str[i] = '\0';
        if (i && !search(word_list, temp_str))
            add(word_list, temp_str);
    }
    print(word_list);
    return 0;
}

int search(word_t *word_list, char *str)
{
    while (word_list != NULL)
    {
        if (!strcmp(word_list->value, str))
        {
            fprintf(stderr, "search() :found word \"%s\" count -> %d\n", str, ++(word_list->count));
            return word_list->count;
        }
        word_list = word_list->next;
    }
    return 0;
}
void add(word_t *word_list, char *str)
{
    while (word_list->next != NULL)
        word_list = word_list->next;
    word_list = word_list->next = (word_t *)calloc(1, sizeof(word_t));
    strncpy(word_list->value, str, LEN);
    word_list->count = 1;
    word_list->next = NULL;
    fprintf(stderr, "add() :add word \"%s\"\n", str);
    return;
}
void print(word_t *word_list)
{
    word_t *top_three[3] = {NULL};
    word_t *p = word_list;
    int max_count = 0;
    for (int i = 0; i < 3; max_count = 0, p = word_list, i++)
    {
        while (p != NULL)
        {
            if (max_count < p->count)
            {
                top_three[i] = p;
                max_count = p->count;
            }
            p = p->next;
        }
        top_three[i]->count = 0;
    }
    for (int i = 0; i < 3 && top_three[i]; i++)
        puts(top_three[i]->value);
}