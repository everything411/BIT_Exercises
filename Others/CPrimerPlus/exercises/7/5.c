#include <stdio.h>
int main(void)
{
	char ch[1024];
	int count = 0, subs = 0;
	while ((ch[count++] = getchar()) != '#')
		switch (ch[count - 1])
		{
		case '.':
			subs++;
			ch[count - 1] = '!';
			break;
		case '!':
			subs++;
			ch[count - 1] = ch[count] = '!';
			count++;
			break;
		}
	printf("The number of substitutions is %d.\n", subs);
	return 0;
}