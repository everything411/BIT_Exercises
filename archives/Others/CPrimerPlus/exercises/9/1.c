#include <stdio.h>
double min(double x, double y)
{
	return (x < y) ? x : y;
}
int main(void)
{
	double num1 = 12.3;
	double num2 = 15.6;
	printf("Numbers:%f and %f.The smaller is %f.\n", num1, num2, min(num1, num2));
	return 0;
}