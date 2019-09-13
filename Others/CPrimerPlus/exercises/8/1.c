#include <stdio.h>
int main(void)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != EOF)
		count++;
	printf("There are %d characters up to the end of file.\n", count);
	return 0;
}