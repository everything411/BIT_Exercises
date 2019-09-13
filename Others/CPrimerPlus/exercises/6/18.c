#include <stdio.h>
#define DUNBAR 150
int main(void)
{
	int friends = 5;
	for (int week = 0; friends <= DUNBAR; week++)
	{
		friends -= week;
		friends *= 2;
		printf("Week %d ,Rabnud has %d friends.\n", week, friends);
	}
	return 0;
}