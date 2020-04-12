/* This program is written by Whitesad originally */
/* Slightly modified by everything411 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5000

bool isfor = false;
int retract = 0;
void format(char ch, char next);
void set_for(char *str);
void Retract(int n);
int main(void)
{
    char *code = (char *)calloc(MAX, sizeof(char));
    char ch;
    int count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch != '\n')
            code[count++] = ch;
    }
    for (int i = 0; code[i]; i++)
    {
        if (code[i] == 'f' || code[i] == ';' || code[i] == ')')
            set_for(&code[i]);
        if (code[i] == ')' && strncmp(&code[i], "){", 2) == 0)
        {
            printf(")\n");
            Retract(retract);
            continue;
        }
        format(code[i], code[i + 1]);
    }
    free(code);
    return 0;
}
void set_for(char *str)
{
    static int dot;
    if (strncmp(str, "for", 3) == 0)
    {
        isfor = true;
        dot = 0;
    }
    if (*str == ';')
        dot++;
    if (*str == ')' && dot == 2)
        isfor = false;
}
void format(char ch, char next)
{
    if (ch == '>')
        printf("%c\n", ch);
    else if (ch == '{')
    {
        printf("%c\n", ch);
        retract++;
        Retract(retract);
    }
    else if (ch == '}')
    {
        printf("}\n");
        retract--;
        if (next == '}')
            Retract(retract - 1);
        else
            Retract(retract);
    }
    else if (ch == ';')
    {
        if (isfor == false)
        {
            printf("%c\n", ch);
            if (next == '}')
                Retract(retract - 1);
            else
                Retract(retract);
        }
        else
            putchar(';');
    }
    else
        printf("%c", ch);
}
void Retract(int n)
{
    for (int i = 0; i < 4 * n; i++)
        putchar(' ');
}