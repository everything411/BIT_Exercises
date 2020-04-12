#include <stdio.h>
int main(void)
{
	double num;
	printf("Input an floating-number:");
	scanf("%lf", &num);
	printf("The input is %lf or %le\n", num, num);
	printf("The input is %+lf or %lE\n", num, num);
	return 0;
}