#include <stdio.h>
#include <string.h>
const int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char *checksum = "10X98765432";
char *id_convert(char *);
char checksum_calc(char *);
_Bool checksum_check(char *);
int main(int argc, char const *argv[])
{
    int total;
    static char id[64];
    scanf("%d", &total);
    while (~scanf("%s", id))
        if (strlen(id) == 15)
            puts(id_convert(id));
        else
            puts(checksum_check(id) ? "Valid" : "Invalid");
    return 0;
}
char checksum_calc(char *id)
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
        sum += weight[i] * (id[i] - '0');
    sum %= 11;
    return checksum[sum];
}
_Bool checksum_check(char *id)
{
    return strlen(id) == 18 && checksum_calc(id) == id[17];
}
char *id_convert(char *id)
{
    _Bool is_100 = !strcmp(id + 12, "996") || !strcmp(id + 12, "997") || !strcmp(id + 12, "998") || !strcmp(id + 12, "999");
    char temp[32];
    strcpy(temp, id + 6);
    id[6] = 0;
    strcat(id, is_100 ? "18" : "19");
    strcat(id, temp);
    id[17] = checksum_calc(id);
    id[18] = 0;
    return id;
}