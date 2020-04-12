#include <stdio.h>
void larger_of(double *x, double *y)
{
	if (*x < *y)
		*x = *y;
	else
		*y = *x;
}
int main(void)
{
	double num1 = 12.3;
	double num2 = 15.6;
	printf("Numbers are %f and %f.\n", num1, num2);
	larger_of(&num1, &num2);
	printf("Now they are %f and %f.\n", num1, num2);
	return 0;
}