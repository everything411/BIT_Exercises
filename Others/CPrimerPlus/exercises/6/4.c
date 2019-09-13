#include <stdio.h>
int main(void)
{
	char count = 0;
	for (char i = 0; i < 6; i++)
	{
		for (int j = 0; j <= i; j++, count++)
			printf("%c", count + 'A');
		printf("\n");
	}
	return 0;
}
