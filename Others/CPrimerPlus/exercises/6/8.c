#include <stdio.h>
int main(void)
{
	double one, two;
	printf("Enter two floating-point numbers:");
	while (scanf("%lf%lf", &one, &two) == 2)
	{
		printf("%f\n", (one - two) / (one * two));
	}
	return 0;
}