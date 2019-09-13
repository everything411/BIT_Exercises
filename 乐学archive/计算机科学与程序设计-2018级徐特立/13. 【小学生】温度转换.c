#include <stdio.h>
int main(int argc, char const *argv[])
{
    int type;
    double temperature;
    scanf("%d%lf", &type, &temperature);
    if (type == 1)
    {
        printf("The Centigrade is %.2f\n", (temperature - 32.0) * 5.0 / 9.0);
    }
    else
    {
        printf("The Fahrenheit is %.2f\n", (temperature * 9.0 / 5) + 32);
    }
    return 0;
}
