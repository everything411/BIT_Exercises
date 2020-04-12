/* Use long long */
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int case_count;
    long long size;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        scanf("%lld", &size);
        printf("%lld\n", (size * size + 1) / 2);
    }
    return 0;
}
