#include <stdio.h>
unsigned long Fibonacci(unsigned n)
{
	unsigned long prev, curr, next;
	prev = curr = next = 1;
	while (n-- > 2)
	{
		prev = curr;
		curr = next;
		next = curr + prev;
	}
	curr = next;
	return curr;
}
int main(void)
{
	for (int i = 1; i <= 20; i++)
		printf("Fibonacci(%d) is %lu.\n", i, Fibonacci(i));
	return 0;
}