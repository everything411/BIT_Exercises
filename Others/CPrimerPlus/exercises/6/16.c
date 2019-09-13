#include <stdio.h>
int main(void)
{
	double Daphne = 100.0, Deirdre = 100.0;
	int year = 0;
	while (Daphne >= Deirdre)
	{
		Daphne += 0.1 * Daphne;
		Deirdre *= 1.05;
		year++;
	}
	printf("It takes %d years for the value of Deirdre’s investment "
		   "to exceed the value of Daphne’s investment.\nDaphne:%f\tDeirdre:%f\n",
		   year, Daphne, Deirdre);
	return 0;
}