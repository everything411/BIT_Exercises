#include <stdio.h>
double cube(double n);
int main(void)
{
	double num = 0;
	printf("Input a type double number:");
	scanf("%lf", &num);
	printf("%f\n", cube(num));
	return 0;
}
double cube(double n)
{
	return n * n * n;
}