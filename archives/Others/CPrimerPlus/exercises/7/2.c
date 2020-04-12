#include <stdio.h>
int main(void)
{
	char ch[1024];
	int count = 0;
	int i;
	while ((ch[count++] = getchar()) != '#')
		;
	for (i = 0; i < count; i++)
	{
		printf("%d ", ch[i]);
		if (!(i % 8))
			putchar('\n');
	}
	return 0;
}