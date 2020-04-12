#include <stdio.h>
void dbl_reverse(double *arr, int n);
int main(void)
{
	double source[5] = {1.5, 4.5, 3.2, 0.7, -4.6};
	printf("Values stored in the array are %f %f %f %f %f.\n",
		   *(source + 0), *(source + 1), *(source + 2),
		   *(source + 3), *(source + 4));
	dbl_reverse(source, 5);
	printf("Now they are %f %f %f %f %f.\n",
		   *(source + 0), *(source + 1), *(source + 2),
		   *(source + 3), *(source + 4));
	return 0;
}
void dbl_reverse(double *arr, int n)
{
	double temp[n];
	for (int i = 0; i < n; i++)
		temp[n - i - 1] = arr[i];
	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
}