#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n, num = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%3d", num++);
        putchar('\n');
    }
    return 0;
}
