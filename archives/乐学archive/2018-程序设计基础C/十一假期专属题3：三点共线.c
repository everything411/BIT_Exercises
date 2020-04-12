#include <stdio.h>
int main(int argc, char const *argv[])
{
    double x1, y1, x2, y2, x3, y3;
    scanf("(%lf,%lf)(%lf,%lf)(%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3);
    if(x1 == x2 || x2 == x3 || x3 == x1)
    {
        if (x1 == x2 && x2 == x3)
            puts("Yes");
        else
            puts("No");
        return 0;
    }
    if (((y1 - y2) / (x1 - x2)) == ((y2 - y3) / (x2 - x3)))
        puts("Yes");
    else
        puts("No");
    return 0;
}
