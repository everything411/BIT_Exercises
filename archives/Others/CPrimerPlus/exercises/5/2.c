#include <stdio.h>
int main(void)
{
	int num = 0;
	printf("Input an integer:");
	scanf("%d", &num);
	int max = num + 10;
	while (num <= max)
	{
		printf("%d ", num++);
	}
	printf("\n");
	return 0;
}