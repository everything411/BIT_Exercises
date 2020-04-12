#include <stdio.h>
int main(int argc, char const *argv[])
{
    char buffer_1[120], buffer_2[120];
    long long val_1 = 0, val_2 = 0;
    scanf("%s%s", buffer_1, buffer_2);
    for (int i = 0; buffer_1[i]; i++)
        val_1 += buffer_1[i];
    for (int i = 0; buffer_2[i]; i++)
        val_2 += buffer_2[i];
    printf("%lld\n", val_1 * val_2);
    return 0;
}
