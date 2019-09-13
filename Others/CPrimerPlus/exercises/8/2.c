#include <stdio.h>
void print(char ch);
int main(void)
{
	int count = 0;
	char ch;
	while ((ch = getchar()) != EOF)
	{
		print(ch);
		while (!(count++ % 10) && count)
			putchar('\n');
	}
	return 0;
}
void print(char ch)
{
	if (ch >= ' ' || ch == '\n' || ch == '\t')
		printf("%d:%c ", ch, ch);
	else
	{
		printf("%d:^%c ", ch, ch + 64);
	}
}