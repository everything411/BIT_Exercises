#include <stdio.h>
#include <string.h>
#include <stdint.h>
short char_map[65536];
char str[65536][8];
char buf[8];
int main(void)
{
    char ch;
    uint16_t ucs_val;
    int repeat_flag = 0;
    while ((ch = getchar()) != EOF)
    {
        ucs_val = 0;
        if ((ch & 0x80) == 0)
        {
            buf[0] = ch;
            buf[1] = 0;
            ucs_val = ch;
        }
        else if ((ch & 0xf0) == 0xf0)
        {
            buf[0] = ch;
            buf[1] = getchar();
            buf[2] = getchar();
            buf[3] = getchar();
            buf[4] = 0;
            ucs_val = 0;
            // out of range
        }
        else if ((ch & 0xe0) == 0xe0)
        {
            buf[0] = ch;
            buf[1] = getchar();
            buf[2] = getchar();
            buf[3] = 0;
            ucs_val = ((uint16_t)(buf[0] & 0x0f) << 12) | ((uint16_t)(buf[1] & 0x3f) << 6) | ((uint16_t)(buf[2] & 0x3f));
        }
        else if ((ch & 0xc0) == 0xc0)
        {
            buf[0] = ch;
            buf[1] = getchar();
            buf[2] = 0;
            ucs_val = ((uint16_t)(buf[0] & 0x1f) << 6) | ((uint16_t)(buf[1] & 0x3f));
        }
        char_map[ucs_val]++;
        strcpy(str[ucs_val], buf);
    }
    for (int i = 128; i < 65536; i++)
    {
        if (char_map[i] > 1)
        {
            repeat_flag = 1;
            printf("%s %#06x %d\n", str[i], i, char_map[i]);
        }
    }
    if (!repeat_flag)
    {
        puts("No repeat!");
    }

    return 0;
}