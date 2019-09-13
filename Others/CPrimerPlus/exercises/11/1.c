#include <stdio.h>
void get(int n, char *dest)
{
	while (n-- > 0)
		*dest++ = getchar();
}

int main(void)
{
	char ch[12];
	get(12, ch);
	return 0;
}