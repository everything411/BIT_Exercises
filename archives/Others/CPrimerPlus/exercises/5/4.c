#include <stdio.h>
int main(void)
{
	const double IN_PER_FT = 12.0;
	const double CM_PER_IN = 2.54;
	const double CM_PER_FT = 30.48;
	double height = 0.0;
	double in;
	int ft;

	printf("Enter a height in centimeters:");
	scanf("%lf", &height);
	while (height > 0.0)
	{
		in = height / CM_PER_IN;
		ft = in / IN_PER_FT;
		printf("%.1f cm = %d feet, %.1f inches.\n",
			   height, ft, in - (double)ft * IN_PER_FT);
		printf("Enter a height in centimeters (<=0 to quit):");
		scanf("%lf", &height);
	}
	printf("bye\n");
	return 0;
}