#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STR "123456"
int atoi(char *ch)
{
	size_t len = strlen(ch);
	char *testit = ch;
	int ret;
	if (*ch == '+' || *ch == '-')
		testit++, len--;
	for (int i = 0; i < len; i++)
		if (!isdigit(*(testit + i)))
			return 0;
	sscanf(ch, "%d", &ret);
	return ret;
}
int main(int argc, char **argv)
{
	printf("string:%s --> int:%d\n", STR, atoi(STR));
	return 0;
}