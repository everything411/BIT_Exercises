#include <stdio.h>
#include <string.h>
int main(void)
{
	char first[40];
	printf("Enter your first name:");
	scanf("%s", first);
	printf("\"%s\"\n", first);
	printf("\"%20s\"\n", first);
	printf("\"%-20s\"\n", first);
	printf("\"%*s\"\n", 3 * (int)strlen(first), first);
	return 0;
}