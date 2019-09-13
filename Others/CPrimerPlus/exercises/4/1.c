#include <stdio.h>
int main(void)
{
	char first[40], last[40];
	printf("Enter your first name and your last name:");
	scanf("%s%s", first, last);
	printf("%s,%s\n", first, last);
	return 0;
}