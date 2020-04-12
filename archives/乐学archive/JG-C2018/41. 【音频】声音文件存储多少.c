#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned long long sampling, bit_len, length;
    unsigned long long kbyte;
    scanf("%lldhz%lld%lld", &sampling, &bit_len, &length);
    kbyte = (2ULL * 60ULL * (bit_len >> 3) * length * sampling) >> 10ULL;
    printf("%llu\n", kbyte);
    return 0;
}
