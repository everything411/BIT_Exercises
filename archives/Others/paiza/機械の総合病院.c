#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char str[100] = {0};
    int digitflag = 0;
    int alphaflag = 0;
    scanf("%s", str);
    for (int i = 0; str[i]; i++)
    {
        str[i] = (islower(str[i]) ? str[i] : tolower(str[i]));
        if (isalpha(str[i]))
        {
            alphaflag = 1;
        }
        else if (isdigit(str[i]))
        {
            digitflag = 1;
        }
    }
    if (digitflag && alphaflag)
    {
        for (int i = 0; str[i]; i++)
        {
            if (str[i] == str[i + 1] && str[i] == str[i + 2]) // compares terminal '\0' here but it is ok
            {
                puts("Invalid");
                return 0;
            }
        }
        puts("Valid");
        return 0;
    }
    else
    {
        puts("Invalid");
    }
    return 0;
}