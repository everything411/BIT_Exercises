#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void *, const void *);
int main(int argc, char const *argv[])
{
    char num[102400] = {0};
    scanf("%s", num);
    qsort(num, strlen(num), sizeof(char), compare);
    puts(num);
    return 0;
}
int compare(const void *i, const void *j)
{
    return -(int)*((const char *)i) + (int)*((const char *)j);
}