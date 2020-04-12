#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned long long height, width, length;
    unsigned long long kbyte;
    scanf("%llu*%llu%llu", &width, &height, &length);
    kbyte = (30ULL * 60ULL * 3ULL * height * width * length) >> 10ULL;
    printf("%llu\n", kbyte);
    return 0;
}
