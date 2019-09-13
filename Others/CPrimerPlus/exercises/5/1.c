#include <stdio.h>
int main(void)
{
	const int MIN_PER_H = 60;
	int min = 1;
	printf("Input time in minutes:");
	scanf("%d", &min);
	while (min > 0)
	{
		printf("The time is %d hour(s) and %d min(s)\n",
			   min / MIN_PER_H, min % MIN_PER_H);
		printf("Input time in minutes:");
		scanf("%d", &min);
	}
	return 0;
}