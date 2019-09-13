#include <stdio.h>
int main(void)
{
	double dbl_1[8], dbl_2[8] = {0.0};
	printf("Enter eight floating-numbers:");
	for (int i = 0; i < 8; i++)
		scanf("%lf", &dbl_1[i]);
	dbl_2[0] = dbl_1[0];
	for (int i = 1; i < 8; i++)
	{
		dbl_2[i] = dbl_2[i - 1] + dbl_1[i];
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%f\t", dbl_1[i]);
	}
	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%f\t", dbl_2[i]);
	}
	printf("\n");
	return 0;
}