#include <stdio.h>
int main(void)
{
	char ch = 0, prev = 0;
	int count = 0;
	while ((ch = getchar()) != '#')
	{
		if (prev == 'e' && ch == 'i')
			count++;
		prev = ch;
	}
	printf("The number of times that the sequence ei occurs is %d.\n",
		   count);
	return 0;
}