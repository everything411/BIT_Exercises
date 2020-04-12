#include <stdio.h>
void chprint(char ch, int times, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < times; j++)
			putchar(ch);
		putchar('\n');
	}
}
int main(void)
{
	printf("chprint(\'1\',4,5) :\n");
	chprint('1', 4, 5);
	printf("chprint(\'a\',5,6) :\n");
	chprint('a', 5, 6);
	return 0;
}