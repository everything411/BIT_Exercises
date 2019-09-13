#include <stdio.h>
void one_three(void);
void two(void);
int main(void)
{
	one_three();
	printf("done!\n");
	return 0;
}
void one_three(void)
{
	printf("one\n");
	two();
	printf("three");
}
void two(void)
{
	printf("two\n");
}