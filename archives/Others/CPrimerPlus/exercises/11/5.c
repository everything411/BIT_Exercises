#include <stdio.h>
char *searchchar(char *search, char ch)
{
	for (int i = 0; search[i] != '\0'; i++)
		if (search[i] == ch)
			return &search[i];
	return NULL;
}

int main(void)
{
	char ch[20];
	char *i;
	while (scanf("%s", ch) == 1)
		if ((i = searchchar(ch, 'a')) == NULL)
			puts("\'a\' not found.");
		else
			printf("%p :%c\n", i, *i);
	return 0;
}