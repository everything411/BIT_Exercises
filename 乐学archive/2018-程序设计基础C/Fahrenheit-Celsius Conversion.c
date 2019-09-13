#include <stdio.h>
int main(int argc, char const *argv[])
{
    int type;
    double temperature;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d%lf", &type, &temperature);
        if (type == 1)
            printf("The Centigrade is %.2f\n", (temperature - 32.0) * 5.0 / 9.0);
        else if (type == 2)
            printf("The Fahrenheit is %.2f\n", (temperature * 9.0 / 5) + 32);
        else
            puts("Wrong input!");
    }
    return 0;
}
