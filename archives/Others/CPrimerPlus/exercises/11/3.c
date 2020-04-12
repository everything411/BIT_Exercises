#include <stdio.h>
void getword(char *dest)
{
	scanf("%s", dest);
	while (getchar() != '\n')
		;
}

int main(void)
{
	char ch[20];
	getword(ch);
	return 0;
}