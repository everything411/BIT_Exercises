#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, S, E;

    scanf("%d%d%d", &n, &S, &E);
    char str[n + 1];
    scanf("%s", str);
    printf("%d\n", (str[S - 1] != str[E - 1]));
    return 0;
}
