#include<stdio.h>
int main(int argc, char const *argv[])
{
    int hour, minute;
    scanf("%d%d", &hour, &minute);
    double degree_min = (double)minute * 6;
    double degree_hour = ((double)minute / 60.0 + hour) * 30;
    double degree = ((degree_min > degree_hour) ? degree_min - degree_hour : - degree_min + degree_hour);
    degree = degree > 180.0 ? 360.0 - degree : degree;
    printf("At %d:%.2d the angle is %.1f degrees.\n", hour, minute, degree);
    return 0;
}
