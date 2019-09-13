#include <stdio.h>
int main(void)
{
	int lower, upper;
	printf("Enter the lower and upper integer limits:");
	scanf("%d%d", &lower, &upper);
	printf("integer\tsquare\tcube\n");
	for (int i = lower; i <= upper; i++)
	{
		printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	}
	return 0;
}
