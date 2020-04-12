#include <stdio.h>
#define PI 3.1415926
int main(void)
{
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("s=%.2f,v=%.2f\n", 2 * PI * r * h, PI * r * r * h);
    return 0;
}