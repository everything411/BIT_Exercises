#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int total, len;
    char str[30];
    scanf("%d ", &total);
    for (int i = 0, digit = 0, upper = 0, lower = 0, other = 0;
         i < total;
         digit = 0, upper = 0, lower = 0, other = 0, i++)
    {
        fgets(str, 30, stdin);
        len = strlen(str);
        str[--len] = 0;
        if (len < 6)
        {
            puts("Not Safe");
            continue;
        }
        for (int j = 0; j < len; j++)
        {
            digit |= !!isdigit(str[j]);
            upper |= !!isupper(str[j]);
            lower |= !!islower(str[j]);
            other |= !(islower(str[j]) || isupper(str[j]) || isdigit(str[j]));
        }

        switch (digit + upper + lower + other)
        {
        case 1:
            puts("Not Safe");
            break;
        case 2:
            puts("Medium Safe");
            break;
        case 3:
        case 4:
            puts("Safe");
            break;
        }
    }
    return 0;
}