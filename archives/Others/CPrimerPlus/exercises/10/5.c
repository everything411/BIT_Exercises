#include <stdio.h>
double dbl_maxdiff(const double *arr, int n);
int main(void)
{
	double source[5] = {1.5, 4.5, 3.2, 0.7, -4.6};
	printf("The difference between the largest and smallest "
		   "elements of {1.5, 4.5, 3.2, 0.7, -4.6}"
		   " is %f.\n",
		   dbl_maxdiff(source, 5));
	return 0;
}
double dbl_maxdiff(const double *arr, int n)
{
	double big, small;
	big = small = *arr;
	for (int i = 0; i < n; i++)
		if (big < arr[i])
			big = arr[i];
	for (int i = 0; i < n; i++)
		if (small > arr[i])
			small = arr[i];
	return big - small;
}