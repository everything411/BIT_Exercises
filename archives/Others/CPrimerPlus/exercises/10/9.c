#include <stdio.h>
void copy_arr(int t_rows, int t_cols, double target[t_rows][t_cols], int s_rows, int s_cols, const double source[s_rows][s_cols]);
void print_arr(int rows, int cols, double arr[rows][cols]);
int main(void)
{
	int rows = 3, cols = 5;
	double source[rows][cols];
	printf("Enter three sets of five double numbers each :\n");
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			scanf("%lf", &source[i][j]);
	double target[rows][cols];
	copy_arr(rows, cols, target, rows, cols, source);
	printf("source:\n");
	print_arr(rows, cols, source);
	printf("target:\n");
	print_arr(rows, cols, target);
	return 0;
}
void copy_arr(int t_rows, int t_cols, double target[t_rows][t_cols], int s_rows, int s_cols, const double source[s_rows][s_cols])
{
	for (int i = 0; i < t_rows; i++)
		for (int j = 0; j < t_cols; j++)
			target[i][j] = source[i][j];
}
void print_arr(int rows, int cols, double arr[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%f ", arr[i][j]);
		printf("\n");
	}
}