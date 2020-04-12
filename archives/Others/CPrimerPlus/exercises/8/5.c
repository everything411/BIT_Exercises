/* guess.c -- an inefficient and faulty number-guesser */
#define G_MAX 100
#define G_MIN 1
#include <stdio.h>
int main(void)
{
	int guess = 50;
	int h_lim = G_MAX;
	int l_lim = G_MIN;
	char ch;
	printf(
		"Pick an integer from 1 to 100. I will try to guess it.\n"
		"Respond with a y if my guess is right with an h if it is high and "
		"with an l if it is low.\nUh...is your number %d?\n",
		guess);
	while ((ch = getchar()) != 'y')
	{
		switch (ch)
		{
		case 'h':
			h_lim = guess;
			guess = (guess + l_lim) / 2;
			break;
		case 'l':
			l_lim = guess;
			guess = (guess + h_lim) / 2;
		default:
			printf("I only understand \'y\',\'h\' and \'l\'.\n");
			while (getchar() != '\n')
				;
			break;
		}
		printf("Well, then, is it %d?\n", guess);
	}
	printf("I knew I could do it!\n");
	return 0;
}