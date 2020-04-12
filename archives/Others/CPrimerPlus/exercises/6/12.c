#include <stdio.h>
double power(double n, int times);
int main(void)
{
	int times;
	printf("Enter the time limit:");
	scanf("%d", &times);
	while (times > 0)
	{
		double sum_one = 0, sum_two = 0;
		for (int i = 1; i <= times; i++)
			sum_one += 1.0 / i;
		for (int i = 1; i <= times; i++)
			sum_two -= 1.0 / i * power(-1.0, i);
		printf("The sum of the first series is %f\n"
			   "The sum of the second series is %f\n"
			   "Enter next set of limits\n",
			   sum_one, sum_two);
		scanf("%d", &times);
	}

	return 0;
}
double power(double n, int times)
{
	double ret = 1;
	for (int i = 0; i < times; i++)
		ret *= n;
	return ret;
}