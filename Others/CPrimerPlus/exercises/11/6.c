#include <stdio.h>
_Bool is_within(char *search, char ch)
{
	for (int i = 0; search[i] != '\0'; i++)
		if (search[i] == ch)
			return 1;
	return 0;
}

int main(void)
{
	char ch[20];
	while (scanf("%s", ch) == 1)
		if (is_within(ch, 'a'))
			puts("\'a\' is within the input.");
		else
			puts("\'a\' not found.");
	return 0;
}