#include <stdio.h>
int main(void)
{
	const int DAY_PER_WEEK = 7;

	int day = 0;
	printf("Enter the number of days:");
	scanf("%d", &day);
	while (day > 0)
	{
		printf("%d days are %d weeks, %d days.\n",
			   day, day / DAY_PER_WEEK, day % DAY_PER_WEEK);
		printf("Enter the number of days(Enter a nonpositive value to quit):");
		scanf("%d", &day);
	}
	return 0;
}