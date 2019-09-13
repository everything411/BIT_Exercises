#include <stdio.h>
int main(void)
{
	char ch[1024];
	int count = 0, subs = 0;
	while ((ch[count++] = getchar()) != '#')
		if (ch[count - 1] == '.')
		{
			subs++;
			ch[count - 1] = '!';
		}
		else if (ch[count - 1] == '!')
		{
			subs++;
			ch[count - 1] = ch[count] = '!';
			count++;
		}
	printf("The number of substitutions is %d.\n", subs);
	return 0;
}