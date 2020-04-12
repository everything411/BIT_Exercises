#include <stdio.h>
void getword(char *dest, int max_ch)
{
	char format[16];
	sprintf(format, "%%%ds", max_ch - 1);
	scanf(format, dest);
	while (getchar() != '\n')
		;
}

int main(void)
{
	char ch[20];
	getword(ch, 20);
	return 0;
}