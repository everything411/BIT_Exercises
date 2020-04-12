#include <stdio.h>
#include <string.h>
char *gets(char *__str);
int main(void)
{
    char key_word[200];
    int count = 0;
    int str_count;
    scanf("%d ", &str_count);
    char str[str_count][200];
    for (int i = 0; i < str_count; i++)
        gets(str[i]);
    gets(key_word);
    int len_key_word = strlen(key_word);
    for (int j = 0; j < str_count; j++)
    {
        int len = strlen(str[j]);
        for (int i = 0; i < len; i++)
            count += !strncmp(str[j] + i, key_word, len_key_word);
    }
    printf("%d\n", count);
    return 0;
}