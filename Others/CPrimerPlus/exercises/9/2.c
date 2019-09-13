#include <stdio.h>
void chline(char ch, int i, int j)
{
	int temp;
	while (j-- > 0)
	{
		temp = i;
		while (temp-- > 0)
			putchar(ch);
		putchar('\n');
	}
}
int main(void)
{
	printf("chline(\'1\',3,2) :\n");
	chline('1', 3, 2);
	printf("chline(\'a\',5,6) :\n");
	chline('a', 5, 6);
	return 0;
}