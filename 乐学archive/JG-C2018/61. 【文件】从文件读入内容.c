#include <stdio.h>
int main(int argc, char const *argv[])
{
    char filename[128];
    char buffer[2048];
    FILE *fp;
    gets(filename);
    fp = fopen(filename, "r");
    while (fgets(buffer, 2048, fp))
        fputs(buffer, stdout);
    fclose(fp);
    return 0;
}
