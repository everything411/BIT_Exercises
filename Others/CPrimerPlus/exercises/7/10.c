#include <stdio.h>
#define RATE1 0.15
#define RATE2 0.28
#define BASE_TAX1 (RATE1 * break_money)

int main(void)
{
	double income, tax, break_money;
	while (1)
	{
		printf(
			"******************************************\n"
			"Enter the tax category:\n"
			"1) Single			2) Head of Household\n"
			"3) Married, Joint	4) Married, Separate\n"
			"Enter other characters to quit\n"
			"*******************************************\n");
		switch (getchar())
		{
		case '1':
			break_money = 17850.0;
			break;
		case '2':
			break_money = 23900.0;
			break;
		case '3':
			break_money = 29750.0;
			break;
		case '4':
			break_money = 14875.0;
			break;
		default:
			return 0;
		}
		while (getchar() != '\n')
			;
		printf("Enter the taxable income:");
		scanf("%lf", &income);
		if (income <= break_money)
			tax = income * RATE1;
		else
			tax = BASE_TAX1 + (income - break_money) * RATE2;
		printf("The taxes is %f.\n", tax);
	}
}