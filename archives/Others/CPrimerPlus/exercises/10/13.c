#include <stdio.h>
#define LEN 5
void input(double arr[][LEN], int n);
double average(double arr[], int n);
double average_all(double arr[][LEN], int n);
double max_all(double arr[][LEN], int n);
void print_result(double result[]);
int main(void)
{
	double data[3][LEN];
	double resu[LEN];
	input(data, 3);
	for (int i = 0; i < 3; i++)
		resu[i] = average(data[i], LEN);
	resu[3] = average_all(data, 3);
	resu[4] = max_all(data, 3);
	print_result(resu);
	return 0;
}

void input(double arr[][LEN], int n)
{
	printf("Enter three sets of five double numbers each :\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < LEN; j++)
			scanf("%lf", &arr[i][j]);
}

void print_result(double result[])
{
	printf("The averages of each set of five values are %f %f %f.\n", result[0], result[1], result[2]);
	printf("The average of all the values is %f.\n", result[3]);
	printf("The largest value of the 15 values is %f.\n", result[4]);
}

double max_all(double arr[][LEN], int n)
{
	double ret = **arr;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < LEN; j++)
			if (ret < arr[i][j])
				ret = arr[i][j];
	return ret;
}

double average_all(double arr[][LEN], int n)
{
	double total, ret;
	total = ret = 0.0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < LEN; j++)
			total += arr[i][j];
	return total / (n * LEN);
}
double average(double arr[], int n)
{
	double total;
	for (int i = 0; i < n; i++)
		total += arr[i];
	return total / n;
}