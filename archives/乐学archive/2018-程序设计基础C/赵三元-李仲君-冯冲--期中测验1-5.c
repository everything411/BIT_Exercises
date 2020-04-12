/*
Compile with gcc 4.8
*/
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[256];
    int char_count[256] = {0};
    char *pos;
    char num_temp[16];
    int num_len;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        char_count[str[i]]++;
    for (int i = 0; i < 256; i++)
        if (char_count[i] > 1)
        {
            sprintf(num_temp, "%d", char_count[i]);
            pos = strrchr(str, i);
            num_len = strlen(num_temp);
            memmove(pos + num_len, pos + 1, strlen(pos + 1) + 1);
            memmove(pos, num_temp, num_len);
        }
    puts(str);
    return 0;
}
