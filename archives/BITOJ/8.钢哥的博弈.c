#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    if (n % 4)
        puts("YES");
    else
        puts("NO");
    return 0;
}
