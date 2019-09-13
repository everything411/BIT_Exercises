#include <stdio.h>
void input(int rows, int cols, double arr[rows][cols]);
double average(int n, double arr[n]);
double average_all(int rows, int cols, double arr[rows][cols]);
double max_all(int rows, int cols, double arr[rows][cols]);
void print_result(double result[]);
int main(void)
{
	double data[3][5];
	double resu[5];
	input(3, 5, data);
	for (int i = 0; i < 3; i++)
		resu[i] = average(5, data[i]);
	resu[3] = average_all(3, 5, data);
	resu[4] = max_all(3, 5, data);
	print_result(resu);
	return 0;
}

void input(int rows, int cols, double arr[rows][cols])
{
	printf("Enter three sets of five double numbers each :\n");
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			scanf("%lf", &arr[i][j]);
}

void print_result(double result[])
{
	printf("The averages of each set of five values are %f %f %f.\n", result[0], result[1], result[2]);
	printf("The average of all the values is %f.\n", result[3]);
	printf("The largest value of the 15 values is %f.\n", result[4]);
}

double max_all(int rows, int cols, double arr[rows][cols])
{
	double ret = **arr;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (ret < arr[i][j])
				ret = arr[i][j];
	return ret;
}

double average_all(int rows, int cols, double arr[rows][cols])
{
	double total, ret;
	total = ret = 0.0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			total += arr[i][j];
	return total / (rows * cols);
}
double average(int n, double arr[n])
{
	double total;
	for (int i = 0; i < n; i++)
		total += arr[i];
	return total / n;
}