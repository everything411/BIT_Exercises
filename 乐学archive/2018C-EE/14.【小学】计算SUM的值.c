#include<stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    double sum = 0.0;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
        sum += 1.0 / (double)i;
    printf("sum=%f\n", sum);
    return 0;
}