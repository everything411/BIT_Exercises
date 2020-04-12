#include <stdio.h>
double calc(double one, double two);
int main(void)
{
	double one, two;
	printf("Enter two floating-point numbers:");
	while (scanf("%lf%lf", &one, &two) <= 2)
	{
		printf("%f\n", calc(one, two));
	}
	return 0;
}
double calc(double one, double two)
{
	return (one - two) / (one * two);
}