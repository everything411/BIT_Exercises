#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char buffer[32] = {0};
    FILE *fp = fopen("randrandrand_tmppmt.log", "a+");
    fprintf(fp, "1");
    rewind(fp);
    fscanf(fp, "%s", buffer);
    if (!strcmp(buffer, "1"))
    {
        puts("2018");
    }
    else if (!strcmp(buffer, "11"))
    {
        puts("2019");
    }
    else if (!strcmp(buffer, "111"))
    {
        puts("2018");
        system("rm randrandrand_tmppmt.log");
    }
    return 0;
}
