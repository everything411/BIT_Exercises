#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char **argv)
{
	char opt = 'p';
	char ch;
	if (argc > 1)
	{
		if (strcmp(argv[1], "-p"))
		{
			opt = 'p';
		}
		else if (strcmp(argv[1], "-u"))
		{
			opt = 'u';
		}
		else if (strcmp(argv[1], "-l"))
		{
			opt = 'l';
		}
	}
	switch (opt)
	{
	case 'p':
		while ((ch = getchar()) != EOF)
			putchar(ch);
		break;
	case 'u':
		while ((ch = getchar()) != EOF)
			putchar(toupper(ch));
		break;
	case 'l':
		while ((ch = getchar()) != EOF)
			putchar(tolower(ch));
		break;
	default:
		printf("Usage :%s [-pul]\n", argv[0]);
		return 1;
	}
	return 0;
}