#include <stdio.h>
#define CUP_PER_PINT 2.0
#define OUNCE_PER_CUP 8.0
#define TABLESPOON_PER_OUNCE 2.0
#define TEASPOON_PER_TABLESPOON 3.0
int main(void)
{
	double cups;
	printf("Enter a volume in cups:");
	scanf("%lf", &cups);
	printf("The volumes in pints:%f\n"
		   "ounces:%f\ntablespoons:%f\nteaspoons:%f\n",
		   cups / CUP_PER_PINT,
		   cups * OUNCE_PER_CUP, cups * OUNCE_PER_CUP * TABLESPOON_PER_OUNCE,
		   cups * OUNCE_PER_CUP * TABLESPOON_PER_OUNCE * TEASPOON_PER_TABLESPOON);
	return 0;
}