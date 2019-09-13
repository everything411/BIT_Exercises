#include <stdio.h>
int main(void)
{
	int lower, upper, sum;
	printf("Enter lower and upper integer limits:");
	while (scanf("%d%d", &lower, &upper) == 2)
	{
		sum = 0;
		for (int i = lower; i <= upper; i++)
			sum += i * i;
		printf("The sums of the squares from %d to %d is %d"
			   "\nEnter next set of limits",
			   lower * lower, upper * upper, sum);
	}
	return 0;
}