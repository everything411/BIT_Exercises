#include <stdio.h>
int main(void)
{
	char ch;
	printf("Enter an uppercase letter:");
	scanf("%c", &ch);
	for (char i = 'A'; i <= ch; i++)
	{
		for (int j = ch - i; j-- > 0;)
			printf(" ");
		for (int j = 'A'; j <= i; j++)
			printf("%c", j);
		for (int j = i - 1; j >= 'A'; j--)
			printf("%c", j);
		printf("\n");
	}
	return 0;
}
