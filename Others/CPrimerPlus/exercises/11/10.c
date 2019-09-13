#include <stdio.h>
#include <string.h>
#define LEN 256
void remove_spaces(char ch[])
{
	char *space;
	size_t len = strlen(ch);
	char tmp[len];
	while ((space = strchr(ch, ' ')))
	{
		strncpy(tmp, space + 1, len);
		strncpy(space, tmp, len);
	}
}
int main(void)
{
	char source[LEN];
	while (fgets(source, LEN, stdin) && *source != '\n')
	{
		remove_spaces(source);
		fputs(source, stdout);
	}
	return 0;
}