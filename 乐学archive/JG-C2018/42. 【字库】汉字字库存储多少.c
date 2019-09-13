#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned long long size, number;
    unsigned long long byte;
    scanf("%lld%lld", &size, &number);
    byte = size * size * number >> 3;
    printf("%llu\n", byte);
    return 0;
}
