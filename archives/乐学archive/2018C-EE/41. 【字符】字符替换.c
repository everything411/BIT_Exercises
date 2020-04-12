#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *gets(char *s);
int main(int argc, char const *argv[])
{
    char *source = calloc(20480, sizeof(char));
    char *from = calloc(5120, sizeof(char));
    char *to = calloc(5120, sizeof(char));
    gets(source);
    gets(from);
    gets(to);
    char *pos = source;
    int from_len = strlen(from);
    int to_len = strlen(to);
    if (strcmp(from, to))
        while ((pos = strstr(pos, from)))
        {
            memmove(pos + to_len, pos + from_len, strlen(pos + from_len) + 1);
            memmove(pos, to, to_len);
            pos = pos + to_len;
        }
    puts(source);
    free(source);
    free(from);
    free(to);
    return 0;
}
