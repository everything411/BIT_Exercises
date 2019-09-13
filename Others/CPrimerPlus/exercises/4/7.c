#include <stdio.h>
#include <float.h>
int main(void)
{
	float numf = 1.0 / 3.0;
	double numd = 1.0 / 3.0;
	printf(
		"FLT_DIG==%d\tDBL_DIG==%d\n"
		"digits\tfloat\tdouble\n"
		"4\t%.4f\t%.4lf\n"
		"12\t%.12f\t%.12lf\n"
		"16\t%.16f\t%.16lf\n",
		FLT_DIG, DBL_DIG, numf, numd, numf, numd, numf, numd);
	return 0;
}