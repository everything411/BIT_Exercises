#include <stdio.h>
int main(void)
{
	int integers[8];
	printf("Enter eight integers:");
	for (int i = 0; i < 8; i++)
		scanf("%d", &integers[i]);
	int count = 7;
	while (count-- > 0)
	{
		printf("%d ", integers[count]);
	}
	printf("\n");
	return 0;
}
