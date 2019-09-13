#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, ans;
    scanf("%d%d", &a, &b);
    ans = a + b;
    for (int i = 0; i < ans; i++)
        printf("Wang!");
    return 0;
}
