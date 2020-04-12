#include <stdio.h>
int main(void)
{
	char ch;
	int s_count = 0, n_count = 0, o_count = 0;
	while ((ch = getchar()) != '#')
		switch (ch)
		{
		case ' ':
			s_count++;
			break;
		case '\n':
			n_count++;
			break;
		default:
			o_count++;
		}
	printf("There are %d spaces,%d newline characters and %d other characters",
		   s_count, n_count, o_count);
	return 0;
}