#include<stdio.h>
int main(void)
{
    char integer[16];
    char pinyin[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    scanf("%s", integer);
    for(int i = 0; integer[i]; i++)
    {
        if (i != 0)
            putchar(' ');
        printf("%s",integer[i] != '-' ? pinyin[(size_t)(integer[i] - '0')] : "fu");
    }
    putchar('\n');
    return 0;
}
