#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char *gets(char *);
int main(int argc, char const *argv[])
{
    char ch;
    int count;
    int diff_flag = 0;
    scanf("%c%d", &ch, &count);
    getchar();
    int size = count * (count + 1);
    char(*char_map)[count + 1] = calloc(size, sizeof(char));
    char(*rev_map)[count + 1] = calloc(size, sizeof(char));
    for (int i = 0; i < count; i++)
    {
        gets(char_map[i]);
    }
    for (int i = 0; i < size; i++)
    {
        ((char *)char_map)[i] = ((char *)char_map)[i] == '@' ? ch : ((char *)char_map)[i];
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            rev_map[i][j] = char_map[count - i - 1][count - j - 1];
        }
    }
    for (int i = 0; i < count; i++)
    {
        diff_flag += strcmp(char_map[i], rev_map[i]);
    }
    if (!diff_flag)
    {
        puts("bu yong dao le");
    }
    for (int i = 0; i < count; i++)
    {
        puts(rev_map[i]);
    }
    free(rev_map);
    free(char_map);
    return 0;
}
