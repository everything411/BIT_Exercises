#include <stdio.h>
int main(int argc, char const *argv[])
{
    double grade, percent;
    int credit;
    scanf("%d%lf", &credit, &grade);

    if (grade < 60.0)
        percent = 0.0;
    else if (grade < 69.9)
        percent = 1.0;
    else if (grade < 79.9)
        percent = 1.3;
    else if (grade < 89.9)
        percent = 1.4;
    else if (grade < 99.9)
        percent = 1.5;
    else
        percent = 2.0;
    printf("%.2f\n", (double)credit * percent);

    return 0;
}
