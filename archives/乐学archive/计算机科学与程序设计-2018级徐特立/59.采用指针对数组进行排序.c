/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>
#include <stdlib.h>

char *resort(char *a);
int main(int argc, char *argv[])
{

    char a[100];
    gets(a);
    puts(resort(a));
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */
#include <string.h>
int compare(const void *ch_1, const void *ch_2)
{
    return *(const char *)ch_1 - *(const char *)ch_2 > 0 ? 1 : -1;
}
char *resort(char *a)
{
    qsort(a, strlen(a), sizeof(char), compare);
    return a;
}