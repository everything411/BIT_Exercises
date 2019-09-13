#include <stdio.h>
void Temperatures(double temp);
int main(void)
{
	double temp;
	printf("Enter a Fahrenheit temperature:");
	while (scanf("%lf", &temp) != 0)
		Temperatures(temp);
	return 0;
}
void Temperatures(double temp)
{
	const double Fahrenheit = temp;
	const double Celsius = 5.0 / 9.0 * (Fahrenheit - 32.0);
	const double Kelvin = Celsius + 273.16;
	printf("Fahrenheit temperature:%f\n"
		   "Celsius temperature:%f\n"
		   "Kelvin temperature:%f\n",
		   Fahrenheit, Celsius, Kelvin);
}