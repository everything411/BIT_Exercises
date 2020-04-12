#include <stdio.h>
#define OVERTIME_RATE 1.5
#define OVERTIME_TIME 40.0
#define RATE1 0.15
#define BREAK_MONEY1 300.0
#define RATE2 0.20
#define BREAK_MONEY2 450.0
#define RATE3 0.25
#define BASE_TAX1 (RATE1 * BREAK_MONEY1)
#define BASE_TAX2 (BASE_TAX1 + RATE2 * (BREAK_MONEY2 - BREAK_MONEY1))
int main(void)
{
	double time, gross_pay, taxes, net_pay;
	double BASE;
	_Bool flag;
	do
	{
		flag = 0;
		printf(
			"*****************************************************************\n"
			"Enter the number corresponding to the desired pay rate or action:\n"
			"1) $8.75/hr                         2) $9.33/hr\n"
			"3) $10.00/hr                        4) $11.20/hr\n"
			"5) quit\n"
			"*****************************************************************\n");
		switch (getchar())
		{
		case '1':
			BASE = 8.75;
			break;
		case '2':
			BASE = 9.33;
			break;
		case '3':
			BASE = 10.00;
			break;
		case '4':
			BASE = 11.20;
			break;
		case '5':
			return 0;
		default:
			flag = 1;
		}
	} while (flag);
	while (getchar() != '\n')
		;
	printf("Enter the hours worked in a week:");
	scanf("%lf", &time);
	if (time > OVERTIME_TIME)
		time = time + (time - OVERTIME_TIME) * OVERTIME_RATE;
	gross_pay = time * BASE;
	if (gross_pay <= BREAK_MONEY1)
		taxes = gross_pay * RATE1;
	else if (gross_pay <= BREAK_MONEY2)
		taxes = BASE_TAX1 + (gross_pay - BREAK_MONEY1) * RATE2;
	else
		taxes = BASE_TAX2 + (gross_pay - BREAK_MONEY2) * RATE3;
	net_pay = gross_pay - taxes;
	printf("The gross pay is %f, the taxes is %f, and the net pay is %f.\n",
		   gross_pay, taxes, net_pay);
	return 0;
}