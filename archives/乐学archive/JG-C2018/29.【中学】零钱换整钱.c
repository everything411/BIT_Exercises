#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int k = 25 * n / 4;
    if (!(25 * n % 4) && !(k * 6 % 5) && !(k * 9 % 10))
        printf("%d,%d,%d\n", k, k * 6 / 5, k * 9 / 10);
    else
        printf("No change.\n");
    return 0;
}
