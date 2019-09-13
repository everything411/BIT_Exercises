#include <stdio.h>
void copy_arr(double target[], const double source[], int n)
{
	for (int i = 0; i < n; i++)
		target[i] = source[i];
}
int main(void)
{
	const double data[7] = {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2};
	double new[3];
	copy_arr(new, data + 2, 3);
	printf("Copy finished.\n");
	return 0;
}
