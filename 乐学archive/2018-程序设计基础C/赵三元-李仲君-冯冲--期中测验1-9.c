/*
Compile with gcc 4.8
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *gets(char *s);
char *list[44] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum",
                  "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return",
                  "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void",
                  "volatile", "while", "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary",
                  "_Noreturn", "_Static_assert", "_Thread_local"};
int main(int argc, char const *argv[])
{
    char name[512];
    int len;
    gets(name);
    if (*name != '_' && !isalpha(*name))
        goto wrong;
    for (int i = 0; i < 44; i++)
        if (!strcmp(name, list[i]))
            goto wrong;
    len = strlen(name);
    for (int i = 0; i < len; i++)
        if (!isalnum(name[i]) && !isdigit(name[i]) && name[i] != '_')
            goto wrong;
    puts("Yes");
    return 0;
wrong:
    puts("No");
    return 1;
}
