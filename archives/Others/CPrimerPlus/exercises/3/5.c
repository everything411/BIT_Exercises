#include <stdio.h>
#define SEC_PER_YEAR 3.156e7
int main(void)
{
	double years;
	printf("Enter your age in years:");
	scanf("%lf", &years);
	printf("Your age in seconds:%.0f\n", years * SEC_PER_YEAR);
	return 0;
}