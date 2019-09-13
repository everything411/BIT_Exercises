#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int count_u, count_l, count_o;
	char ch;
	count_u = count_l = count_o = 0;
	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
			count_l++;
		else if (isupper(ch))
			count_u++;
		else
			count_o++;
	}
	printf("There are %d uppercase letters, %d lowercase letters "
		   "and %d other characters other characters in the input.\n",
		   count_u, count_l, count_o);
	return 0;
}