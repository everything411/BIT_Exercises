#include <stdio.h>
#include <float.h>
#include <limits.h>
int main(void)
{
	printf("int_max:%d\tint_max+1:%d\n", INT_MAX, INT_MAX + 1);
	printf("uint_max:%u\tuint_max+1:%u\n", UINT_MAX, UINT_MAX + 1);
	printf("double_max:%g\tdouble_max*10:%g\n", DBL_MAX, DBL_MAX * 10);
	printf("double_min:%g\tdouble_min/100:%g\n", DBL_MIN, DBL_MIN / 100);
	return 0;
}