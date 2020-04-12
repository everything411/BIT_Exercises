#include <stdio.h>
int main(void)
{
	float height;
	char name[40];
	printf("Input your height in centimeters and your name:");

	scanf("%f", &height);
	scanf("%s", name);
	printf("%s, you are %f centimeters tall\n", name, height);
	return 0;
}
