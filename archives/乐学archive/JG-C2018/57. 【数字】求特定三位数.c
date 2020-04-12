/**
 * 
 * Run the program commented to generate the answer array
 * 
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[16];
    int min, max;
    for (int i = 1; i <= 3; i++)
    {
        min = i * 100;
        max = min + 100;
        for (int j = min; j < max && j * 3 < 1000; j++)
        {
            sprintf(str, "%d,%d,%d", j, j * 2, j * 3);
            if (strchr(str, '1') && strchr(str, '2') && strchr(str, '3') && strchr(str, '4') &&
                strchr(str, '5') && strchr(str, '6') && strchr(str, '7') && strchr(str, '8') &&
                strchr(str, '9'))
                printf("%s\n", str);
        }
    }
    return 0;
}
 * 
 * 
**/
#include <stdio.h>
char *answer[4] = {"192,384,576\n", "219,438,657\n273,546,819\n", "327,654,981\n", "0,0,0\n"};
int main(int argc, char const *argv[])
{
    int first;
    scanf("%d", &first);
    printf("%s", answer[first > 3 ? 3 : first - 1]);
    return 0;
}
