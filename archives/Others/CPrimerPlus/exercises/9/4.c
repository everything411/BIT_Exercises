#include <stdio.h>
double harmonic(double x, double y)
{
	return 2 * x * y / (x + y);
}
int main(void)
{
	double num1 = 12.3;
	double num2 = 15.6;
	printf("Numbers:%f and %f.The harmonic mean of the two numbers is %f.\n",
		   num1, num2, harmonic(num1, num2));
	return 0;
}