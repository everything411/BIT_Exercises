#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> //to make big news
int main(int argc, char const *argv[])
{
    DIR *dp;
    FILE *fp;
    struct dirent *dirp;
    char *buffer = calloc(10240, sizeof(char));
    char file_name[1024];
    int line_num;
    scanf("%s%d", file_name, &line_num);
    dp = opendir(".");
    fprintf(stderr, "$ ls\n");
    while ((dirp = readdir(dp)) != NULL)
    {
        fprintf(stderr, "%s\n", dirp->d_name);
    }
    closedir(dp);
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        puts("File Name Error.");
        return 1;
    }

    for (int i = 0; i < line_num; i++)
    {
        if (!fgets(buffer, 10240, fp))
        {
            puts("Line No Error.");
            return 1;
        }
    }
    fputs(buffer, stdout);
    free(buffer);
    fclose(fp);
    return 0;
}
