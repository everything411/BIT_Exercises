#include <stdio.h>
#define NUM_PER_QUART 950.0 * 3.0e-23
int main(void)
{
	double quart;
	printf("Enter an amount of water, in quarts:");
	scanf("%lf", &quart);
	printf("The number of water molecules:%.0f\n", quart * NUM_PER_QUART);
	return 0;
}