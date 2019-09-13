#include <iostream>
#include <cmath>
int main(void)
{
    int n;
    int h;
    scanf("%d%d", &n, &h);
    for (int i = 1; i < n - 1; i++)
        printf("%.12lf ", sqrt((1.0 * i / n) * h * h));
    printf("%.12lf\n", sqrt((1.0 * (n - 1) / n) * h * h));

    return 0;
}
