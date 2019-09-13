#include <stdio.h>
void add_arr(const double source1[], const double source2[], double target[], int n);
int main(void)
{
	double source1[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double source2[5] = {2.3, 4.6, 2.9, 4.2, 11.5};
	double target[5];
	add_arr(source1, source2, target, 5);
	for (int i = 0; i < 5; i++)
		printf("%f ", target[i]);
	printf("\n");
	return 0;
}
void add_arr(const double source1[], const double source2[], double target[], int n)
{
	for (int i = 0; i < n; i++)
		target[i] = source1[i] + source1[i];
}