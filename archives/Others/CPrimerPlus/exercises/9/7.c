#include <stdio.h>
int location(char ch)
{
	return (ch >= 'a' && ch <= 'z') ? ch - 'a' + 1 : ((ch >= 'A' && ch <= 'Z') ? ch - 'A' + 1 : -1);
}
int main(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
		if (location(ch) != -1)
			printf("%c is a letter and its numerical location"
				   " in the alphabet is %d.\n",
				   ch, location(ch));
		else
			printf("%c is not a letter.", ch);
	return 0;
}