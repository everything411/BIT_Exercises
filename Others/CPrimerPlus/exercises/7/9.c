#include <stdio.h>
int main(void)
{
	unsigned int num;
	unsigned int div;
	_Bool flag;
	printf("Please enter an integer:");
	scanf("%u", &num);
	for (int i = 2; i <= num; i++)
	{
		flag = 1;
		for (div = 2; (div * div) <= num; div++)
		{
			if (num % div == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%u \n", i);
	}
	printf("\nBye.\n");
	return 0;
}