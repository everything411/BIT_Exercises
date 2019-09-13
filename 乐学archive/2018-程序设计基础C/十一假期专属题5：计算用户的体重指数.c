#include <stdio.h>
int main(int argc, char const *argv[])
{
    double height, weight;
    scanf("%lf%lf", &weight, &height);
    double BMI = weight / height / height;
    if (BMI < 18.5)
        puts("Underweight");
    else if (BMI < 24.0)
        puts("Healthy weight");
    else if (BMI < 28.0)
        puts("Over weight");
    else if (BMI < 32.0)
        puts("Obese");
    else
        puts("Hyperadiposity");
    return 0;
}
