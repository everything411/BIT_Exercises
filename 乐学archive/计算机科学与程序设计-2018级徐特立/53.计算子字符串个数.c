/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>

int countsub(char *str, char *ss);

int main()
{
    char s1[1000] = {0}, s2[100] = {0};
    gets(s1);
    gets(s2);
    printf("%d\n", countsub(s1, s2));
    return 0;
}

   PRESET CODE END - NEVER TOUCH CODE ABOVE */
#include <string.h>

int countsub(char *source, char *target)
{
    int ret_val = 0;
    int len_source = strlen(source);
    int len_target = strlen(target);
    int i;
    for (i = 0; i < len_source && strncmp(source + i, target, len_target); i++)
        ;
    if (i != len_source)
        for (int j = i; j < len_source; j += len_target)
            if (!strncmp(source + j, target, len_target))
                ret_val++;
            else
                break;
    return ret_val;
}