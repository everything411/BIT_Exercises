/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
#include <stdlib.h>

int merge_sort(char *a, char *b, char *c);
int main(int argc, char *argv[])
{

    char a[100];
    char b[100];
    char c[200];

    gets(a);
    gets(b);
    merge_sort(a, b, c);
    puts(c);
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */
#include <string.h>
int compare(const void *ch_1, const void *ch_2)
{
    return *(const char *)ch_1 - *(const char *)ch_2 > 0 ? 1 : -1;
}
int merge_sort(char *a, char *b, char *c)
{
    *c = 0;
    strcat(c, a);
    strcat(c, b);
    qsort(c, strlen(c), sizeof(char), compare);
    return 0;
}