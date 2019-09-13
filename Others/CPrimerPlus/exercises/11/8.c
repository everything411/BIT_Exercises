#include <stdio.h>
#include <string.h>
char *string_in(char *strsrc, char *strin)
{
	return strstr(strsrc, strin);
}

int main(void)
{
	char str1[100], str2[100];
	char *pos;
	printf("Enter two strings, and I can tell you "
		   "if the second string is contained in the first string\n");
	while (scanf("%s%s", str1, str2) == 2)
	{
		if ((pos = string_in(str1, str2)))
			printf("\"%s\" found at %p :%s", str2, pos, pos);
		else
			printf("\"%s\" not found, pos", str2);
	}
	return 0;
}