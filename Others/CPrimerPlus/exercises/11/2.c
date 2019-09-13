#include <stdio.h>
void get(int n, char *dest)
{
	while (n-- > 0)
	{
		*dest++ = getchar();
		if (*(dest - 1) == '\n' || *(dest - 1) == '\t' || *(dest - 1) == ' ')
			break;
	}
}

int main(void)
{
	char ch[12];
	get(12, ch);
	return 0;
}