#include <stdio.h>
int power(int n, int times);
int main(void)
{
	int integers[8];
	for (int i = 0; i < 8; i++)
		integers[i] = power(2, i);
	int i = 0;
	do
	{
		printf("%d ", integers[i]);
		++i;
	} while (i < 8);
	printf("\n");
	return 0;
}
int power(int n, int times)
{
	int ret = 1;
	for (int i = 0; i < times; i++)
		ret *= n;
	return ret;
}