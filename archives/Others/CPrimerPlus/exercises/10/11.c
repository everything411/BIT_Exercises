#include <stdio.h>
void mul_arr(int arr[][5], int n);
void print_arr(int arr[][5], int n);
int main(void)
{
	int source[3][5] =
		{
			{4, 4, 4, 3, 2},
			{5, 8, 2, 6, 2},
			{9, 5, 7, 4, 2}};
	printf("Original array is\n");
	print_arr(source, 3);
	mul_arr(source, 3);
	printf("Now it is\n");
	print_arr(source, 3);
	return 0;
}
void mul_arr(int arr[][5], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			arr[i][j] *= 2;
}
void print_arr(int arr[][5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}