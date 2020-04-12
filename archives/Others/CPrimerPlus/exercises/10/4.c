#include <stdio.h>
int dbl_maxnumindex(const double *arr, int n);
int main(void)
{
	double source[5] = {1.5, 4.5, 3.2, 0.7, -4.6};
	printf("The index of the largest value stored in {1.5, 4.5, 3.2, 0.7, -4.6}"
		   " is %d.\n",
		   dbl_maxnumindex(source, 5));
	return 0;
}
int dbl_maxnumindex(const double *arr, int n)
{
	double num = *arr;
	int ret = 0;
	for (int i = 0; i < n; i++)
		if (num < arr[i])
		{
			num = arr[i];
			ret = i;
		}
	return ret;
}