#include <stdio.h>
int main(void)
{
	double dollars = 1000000.0;
	int year = 0;
	while (dollars >= 0.0)
	{
		dollars *= 1.08;
		dollars -= 100000.0;
		year++;
	}
	printf("It takes %d years  for Chuckie to empty his account.\n", year);
	return 0;
}