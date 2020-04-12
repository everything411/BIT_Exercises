#include <stdio.h>
#define LITERPERGALLON 3.785
#define KMPERMILE 1.609
int main(void)
{
	double miles, gallons;
	printf("Input the number of miles traveled and the number "
		   "of gallons of gasoline consumed:");
	scanf("%lf%lf", &miles, &gallons);
	printf("miles-per-gallon\t\tliters-per-100-km\n%lf\t%lf\n",
		   miles / gallons, gallons * LITERPERGALLON / miles / KMPERMILE / 100.0);
	return 0;
}
