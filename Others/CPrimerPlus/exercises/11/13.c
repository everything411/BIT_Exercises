#include <stdio.h>
int main(int argc, char **argv)
{
	while (argc-- > 1)
		printf("%s ", argv[argc]);
	printf("\n");
	return 0;
}