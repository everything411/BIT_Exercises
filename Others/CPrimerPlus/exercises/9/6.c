#include <stdio.h>
void incorder(double *x, double *y, double *z)
{
	double temp;
	if (*x > *y)
	{
		temp = *y;
		*y = *x;
		*x = temp;
	}
	//now x < y
	if (*y > *z)
	{
		temp = *z;
		*z = *y;
		*y = temp;
	}
	//now y < z and z is the biggest
	if (*x > *y)
	{
		temp = *y;
		*y = *x;
		*x = temp;
	}
	//now x < y < z
}
int main(void)
{
	double num1 = 12.3;
	double num2 = 15.6;
	double num3 = 13.5;
	printf("Numbers are %f, %f and %f.\n", num1, num2, num3);
	incorder(&num1, &num2, &num3);
	printf("Now they are %f, %f and %f.\n", num1, num2, num3);
	return 0;
}