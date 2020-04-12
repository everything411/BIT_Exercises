#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    int bit_1, bit_2, bit_3;
    bit_1 = num / 100;
    bit_2 = num / 10 % 10;
    bit_3 = num % 10;
    printf("%03d\n", bit_1 + bit_3 * 100 + bit_2 * 10);
    return 0;
}
