#include <stdio.h>
int main(void)
{
	char word[256];
	int count = 0;
	printf("Enter something in a line:");
	do
	{
		scanf("%c", &word[count++]);
	} while (word[count - 1] == '\n');
	while (count-- > 0)
	{
		printf("%c", word[count]);
	}
	printf("\n");
	return 0;
}
