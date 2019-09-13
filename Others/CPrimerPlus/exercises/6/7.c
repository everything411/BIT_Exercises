#include <stdio.h>
#include <string.h>
int main(void)
{
	char word[50];
	printf("Enter a single word:");
	scanf("%s", word);
	int len = strlen(word);
	while (len-- > 0)
	{
		printf("%c", word[len]);
	}
	printf("\n");
	return 0;
}
