#include <stdio.h>
int main(int argc, char const *argv[])
{
    int count, number;
    int left;
    int rela_pos = 0;
    scanf("%d%d", &count, &number);
    for (int i = 2; i <= count; i++)
        rela_pos = (rela_pos + number) % i;
    left = rela_pos + 1;
    printf("The left child is NO %d.\n", left);
    return 0;
}