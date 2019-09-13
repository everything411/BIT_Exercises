#include <stdio.h>
#include <ctype.h>
char get_choice(void);
float get_flt(void);
char get_first(void);
int main(void)
{
	float n1, n2;
	char choice;
	printf(
		"Enter the operation of your choice:\n"
		"a. add           s. subtract\n"
		"m. multiply      d. divide\n"
		"q. quit\n");
	while (1)
	{
		if ((choice = get_choice()) == 'q')
		{
			printf("Bye.\n");
			return 0;
		}
		printf("Enter first number:");
		n1 = get_flt();
		printf("Enter second number:");
		while ((n2 = get_flt()) == 0.0 && choice == 'd')
			printf("Enter a number other than 0:");
		while (getchar() != '\n')
			;
		switch (choice)
		{
		case 'a':
			printf("%f + %f = %f\n", n1, n2, n1 + n2);
			break;
		case 's':
			printf("%f - %f = %f\n", n1, n2, n1 - n2);
			break;
		case 'm':
			printf("%f * %f = %f\n", n1, n2, n1 * n2);
			break;
		case 'd':
			printf("%f / %f = %f\n", n1, n2, n1 / n2);
			break;
		default:
			while (getchar() != '\n')
				;
			break;
		}
	}
}
char get_choice(void)
{
	int ch;
	ch = get_first();
	while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
	{
		printf("Please respond with a, s, m, d, or q.\n");
		ch = get_first();
	}
	return ch;
}
float get_flt(void)
{
	float input;
	char ch;
	while (scanf("%f", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a number.\n"
			   "Please enter a number, such as 2.5, -1.78E8, or 3:");
	}
	return input;
}
char get_first(void)
{
	int ch;
	while (isspace(ch = getchar()))
		continue;
	return ch;
}