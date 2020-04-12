#include <stdio.h>
void move_x(int n, char src, char dec);

int main(int argc, char const *argv[])
{
    int count = 1;
    int n;
    char ch1, ch2;
    while (~scanf("%d %c %c", &n, &ch1, &ch2))
    {
        printf("Case: %d\n", count++);
        move_x(n, ch1, ch2);
    }
    return 0;
}

void move_x(int n, char src, char dec) //this function is copied from the presentation
{
    if (n == 1)
    {
        printf("move no.%d from %c to %c\n", n, src, dec);
    }
    else
    {
        char mid = 3 * 'b' - src - dec;
        move_x(n - 1, src, mid);
        printf("move no.%d from %c to %c\n", n, src, dec);
        move_x(n - 1, mid, dec);
    }
}