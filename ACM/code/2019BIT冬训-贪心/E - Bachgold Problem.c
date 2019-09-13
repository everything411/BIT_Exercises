#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    int count;
    scanf("%d", &num);
    count = num / 2;
    printf("%d\n", count);
    for (int i = 0; i < count - 1; i++)
        printf("2 ");
    printf("%d\n", num & 1 ? 3 : 2);
    return 0;
}
