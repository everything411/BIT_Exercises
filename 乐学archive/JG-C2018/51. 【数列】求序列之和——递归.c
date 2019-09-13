#include <stdio.h>
double sum(int);
int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    if (num == 1)
        puts("1");
    else
        printf("%f\n", sum(num));
    return 0;
}
double sum(int num)
{
    if (num > 1)
        return ((num & 1) ? -1.0 : 1.0) / (double)num + sum(num - 1);
    else
        return 1.0;
}