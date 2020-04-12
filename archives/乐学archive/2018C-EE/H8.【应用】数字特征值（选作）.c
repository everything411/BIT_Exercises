#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str_num[100];
    int num;
    int checksum = 0;
    scanf("%d", &num);
    sprintf(str_num, "%d", num);
    int len, pos;
    len = pos = strlen(str_num);
    while (pos--)
        if (!((len - pos + str_num[pos] - '0') % 2))
            checksum += (long long)1 << (len - pos - 1);
    printf("%d\n", checksum);
    return 0;
}
