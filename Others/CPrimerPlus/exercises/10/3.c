#include <stdio.h>
int int_maxnum(const int *arr, int n);
int main(void)
{
	int source[5] = {1, 4, 3, 0, -4};
	printf("The largest value stored in {1, 4, 3, 0, -4}"
		   " is %d.\n",
		   int_maxnum(source, 5));
	return 0;
}
int int_maxnum(const int *arr, int n)
{
	int ret = *arr;
	for (int i = 0; i < n; i++)
		if (ret < arr[i])
			ret = arr[i];
	return ret;
}