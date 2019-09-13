//Written by Whitesad originally
//format with clang-format by everything411
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105
int main(int argc, char const *argv[])
{
    char input[MAX];
    gets(input);
    int len = strlen(input);
    int i, j;
    int count = 0;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1, count++; j < len; j++)
        {
            if (input[j] > input[j - 1])
                count++;
            else
                break;
        }
    }
    printf("%d\n", count);
    return 0;
}