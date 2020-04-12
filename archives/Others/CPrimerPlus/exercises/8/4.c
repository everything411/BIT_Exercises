#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int main(void)
{
	char ch;
	bool inword = false;
	int w_count = 0;
	int l_count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (inword && isalnum(ch)) //in word and count letter
			l_count++;
		else if (inword && !isalnum(ch)) //word ends
			inword = 0;
		else if (!inword && isalnum(ch)) //word begins
		{
			l_count++;
			w_count++;
			inword = true;
		}
	}
	printf("The average number of letters per word is %f.\n", (double)l_count / w_count);
	return 0;
}