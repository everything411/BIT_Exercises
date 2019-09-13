#include <stdio.h>
#define CM_PER_INCH 2.54
int main(void)
{
	double height;
	printf("Enter your height in centimeters:");
	scanf("%lf", &height);
	printf("Your height in inches:%.3f\n", height / CM_PER_INCH);
	return 0;
}