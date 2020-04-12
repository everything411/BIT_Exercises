#include <stdio.h>
int main(void)
{
    FILE *fp;
    int i, j;
    char filename[80];
    scanf("%s", filename);
    fp = fopen(filename, "r");
    fscanf(fp, "%d%d", &i, &j);
    printf("%d\n", i + j);
    fclose(fp);
    return 0;
}
