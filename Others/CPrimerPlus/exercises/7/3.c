#include <stdio.h>
int main(void)
{
	int nums[512];
	int count, e_count, o_count, e_total, o_total;
	count = e_count = o_count = e_total = o_total = 0;

	do
	{
		scanf("%d", &nums[count++]);
		switch (nums[count - 1] % 2)
		{
		case 0:
			e_count++;
			e_total += nums[count - 1];
			break;
		case 1:
			o_count++;
			o_total += nums[count - 1];
		}
	} while (nums[count - 1] != 0);
	printf("The total number of even integers (excluding the 0) entered is %d.\n"
		   "The average value of the even integers is %f.\n"
		   "The total number of odd integers entered is %d.\n"
		   "The average value of the odd integers is %f.\n",
		   e_count, (double)e_total / e_count, o_count, (double)o_total / o_count);
	return 0;
}