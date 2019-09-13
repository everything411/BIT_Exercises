/* addemup.c -- five kinds of statements */
#include <stdio.h>
int main(void) /* finds sum of first 20 integers */
{
	int count, sum, i; /* declaration statement          */
	count = 0;		   /* assignment statement           */
	sum = 0;		   /* ditto                          */
	i = 0;
	printf("Enter an integer:");
	scanf("%d", &i);
	while (count++ < i) /* while                          */
	{
		sum = sum + count * count; /*     statement                  */
	}
	printf("sum = %d\n", sum); /* function statement             */
	return 0;				   /* return statement               */
}