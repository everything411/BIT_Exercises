#include <stdio.h>
int main(int argc, char const *argv[])
{
    int total;
    scanf("%d", &total);
    int number[total];
    for (int i = 0; i < total; i++)
        scanf("%d", number + i);
    int count = total / 2;
    if (total & 1)
    {
        for (int i = 0; i < count; i++)
            printf("%d ", number[i] * number[total - i - 1]);
        printf("%d \n", number[count]);
    }
    else
    {
        for (int i = 0; i < count; i++)
            printf("%d ", number[i] * number[total - i - 1]);
        putchar('\n');
    }

    return 0;
}
