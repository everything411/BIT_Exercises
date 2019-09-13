#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str2[6], str3[6];
    char code[12];
    int checksum = 0;
    scanf("%s%s%s", code, str2, str3);
    strcat(code, str2);
    strcat(code, str3);
    for (int i = 0; i < 11; i++)
        code[i] -= '0';
    for (int i = 0; i < 11; i += 2)
        checksum += code[i];
    checksum *= 3;
    for (int i = 1; i < 11; i += 2)
        checksum += code[i];
    checksum--;
    checksum %= 10;
    checksum = 9 - checksum;
    printf("%d\n", checksum);
    return 0;
}
