#include <stdio.h>
int main(void)
{
	for (int i = 5; i >= 0; i--)
	{
		char j = 'G';
		while (j-- > 'A' + i)
			printf("%c", j);
		printf("\n");
	}
	return 0;
}
