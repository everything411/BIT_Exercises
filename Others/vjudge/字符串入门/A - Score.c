#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int count, i, j;
    scanf("%d", &count);
    char str[100];
    for (i = 0; i < count; i++)
    {
        scanf("%s", str);
        int score = 0;
        int curr = 0;
        int len = strlen(str);
        for (j = 0; j < len; j++)
            if (str[j] == 'O')
                score += ++curr;
            else
                curr = 0;
        printf("%d\n", score);
    }

    return 0;
}
