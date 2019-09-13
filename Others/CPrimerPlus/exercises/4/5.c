#include <stdio.h>
#define BITPERBYTE 8.0
int main(void)
{
	float speed, size;
	char name[40];
	printf("Input the download speed in megabits per second (Mbs)"
		   "and the size of a file in megabytes (MB):");
	scanf("%f", &speed);
	scanf("%f", &size);
	printf("At %.2f megabits per second, a file of %.2f megabytes\n"
		   "downloads in %.2f seconds.\n",
		   speed, size, size * BITPERBYTE / speed);
	return 0;
}
