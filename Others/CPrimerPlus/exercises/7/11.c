#include <stdio.h>
#define ARTICHOKES 2.05
#define BEETS 1.15
#define CARROTS 1.09
#define BREAK_DISCOUNT 100.0
#define DISCOUNT 0.05
#define BREAK_POUND1 5
#define BREAK_POUND2 20
#define S_H_MONEY1 6.5
#define S_H_MONEY2 14.0
#define S_H_MONEY_PER_POUND 0.5
int main(void)
{
	double temp, artichokes, beets, carrots;
	double a_money, b_money, c_money;
	double total_pounds;
	double veg_money, disc_money, s_h_money, total_money;
	temp = artichokes = beets = carrots = 0.0;
	a_money = b_money = c_money = 0.0;
	total_pounds = 0.0;
	veg_money = disc_money = s_h_money = total_money = 0.0;
	_Bool flag = 1;
	printf(
		"***************************************************\n"
		"The ABC Mail Order Grocery\n"
		"a) Artichokes for $2.05 per pound\n"
		"b) Beets for $1.15 per pound\n"
		"c) Carrots for $1.09 per pound\n"
		"q) Exit the ordering process\n"
		"***************************************************\n");
	while (flag)
	{
		printf("Enter a letter to choose one option.\n");
		switch (getchar())
		{
		case 'a':
			printf("Enter the pounds of artichokes desired:");
			scanf("%lf", &temp);
			artichokes += temp;
			break;
		case 'b':
			printf("Enter the pounds of beets desired:");
			scanf("%lf", &temp);
			beets += temp;
			break;
		case 'c':
			printf("Enter the pounds of carrots desired:");
			scanf("%lf", &temp);
			carrots += temp;
			break;
		case 'q':
			flag = 0;
			break;
		default:
			printf("No such vegetables.\n");
			break;
		}
		while (getchar() != '\n')
			;
	}
	a_money = artichokes * ARTICHOKES;
	b_money = beets * BEETS;
	c_money = carrots * CARROTS;
	veg_money = a_money + b_money + c_money;
	printf(
		"Artichokes for $2.05 per pound, %f pounds ordered, costs %f.\n"
		"Beets for $1.15 per pound     , %f pounds ordered, costs %f.\n"
		"Carrots for $1.09 per pound   , %f pounds ordered, costs %f.\n"
		"The total cost of the order is %f.\n",
		artichokes, a_money, beets, b_money, carrots, c_money, veg_money);
	if (veg_money >= BREAK_DISCOUNT)
		disc_money = veg_money * DISCOUNT;
	if (disc_money != 0.0)
		printf("The discount is %f.\n", disc_money);
	total_pounds = artichokes + beets + carrots;
	if (total_pounds <= BREAK_POUND1)
		s_h_money = S_H_MONEY1;
	else if (total_pounds <= BREAK_POUND2)
		s_h_money = S_H_MONEY2;
	else
		s_h_money = S_H_MONEY2 + (total_pounds - BREAK_POUND2) * S_H_MONEY_PER_POUND;
	total_money = veg_money - disc_money + s_h_money;
	printf(
		"The charge for shipping and handling is %f.\n"
		"The grand total of all the charges is %f.\n",
		s_h_money, total_money);
	return 0;
}