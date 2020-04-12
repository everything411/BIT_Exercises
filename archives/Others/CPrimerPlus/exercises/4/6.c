#include <stdio.h>
#include <string.h>
int main(void)
{
	char first[40], last[40];
	printf("Input your first name and your last name:");
	scanf("%s%s", first, last);
	printf("%s %s\n", first, last);
	printf("%*zd %*zd\n", (int)strlen(first), strlen(first),
		   (int)strlen(last), strlen(last));
	printf("%s %s\n", first, last);
	printf("%-*zd %-*zd\n", (int)strlen(first), strlen(first),
		   (int)strlen(last), strlen(last));
	return 0;
}
