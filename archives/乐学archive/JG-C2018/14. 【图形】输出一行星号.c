#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        putchar('*');
    putchar('\n');
    return 0;
}
