#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x;
    scanf("%d", &x);
    puts(x % 2 ? "No" : "Yes");
    return 0;
}
