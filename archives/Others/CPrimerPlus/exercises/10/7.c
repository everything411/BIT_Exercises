#include <stdio.h>
void copy_ptr(double *target, const double *source, int n);
int main(void)
{
	const double data[5][12] =
		{
			{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
			{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
			{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
			{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
			{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}};
	double new[5][12];
	for (int i = 0; i < 5; i++)
		copy_ptr(*(new + i), *(data + i), 12);
	printf("Copy finished.\n");
	return 0;
}
void copy_ptr(double *target, const double *source, int n)
{
	for (int i = 0; i < n; i++)
		*(target + i) = *(source + i);
}