#include <stdio.h>
#include <string.h>
#define LEN 256
int main(void)
{
	char source[10][LEN];
	int count;
	int i, j;
	printf("I will read in up to 10 strings or to EOF.\n");
	for (count = 0; count < 10 && fgets(source[count], LEN, stdin); count++)
		;
	printf(
		"1) print the original list of strings.\n"
		"2) print the strings in ASCII collating sequence.\n"
		"3) print the strings in order of increasing length.\n"
		"4) print the strings in order of the length of the "
		"first word in the string\n"
		"5) quit.\n");
	char *temp[count];
	char *tempword[count];
	char word[count][32];
	char *exchange;
	while (1)
	{

		switch (getchar())
		{
		case '1':
			for (i = 0; i < count; i++)
				fputs(source[i], stdout);
			break;
		case '2':
			for (i = 0; i < count; i++)
				temp[i] = source[i];
			for (i = 0; i < count - 1; i++)
				for (j = i + 1; j < count; j++)
					if (strcmp(temp[i], temp[j]) > 0)
					{
						exchange = temp[i];
						temp[i] = temp[j];
						temp[j] = exchange;
					}
			for (i = 0; i < count; i++)
				fputs(temp[i], stdout);
			break;
		case '3':
			for (i = 0; i < count; i++)
				temp[i] = source[i];
			for (i = 0; i < count - 1; i++)
				for (j = i + 1; j < count; j++)
					if (strlen(temp[i]) > strlen(temp[j]))
					{
						exchange = temp[i];
						temp[i] = temp[j];
						temp[j] = exchange;
					}
			for (i = 0; i < count; i++)
				fputs(temp[i], stdout);
			break;
		case '4':
			for (i = 0; i < count; i++)
				sscanf(source[i], "%s", word[i]);
			for (i = 0; i < count; i++)
				tempword[i] = word[i];
			for (i = 0; i < count; i++)
				temp[i] = source[i];
			for (i = 0; i < count - 1; i++)
				for (j = i + 1; j < count; j++)
					if (strlen(tempword[i]) > strlen(tempword[j]))
					{
						exchange = temp[i];
						temp[i] = temp[j];
						temp[j] = exchange;
						exchange = tempword[i];
						tempword[i] = tempword[j];
						tempword[j] = exchange;
					}
			for (i = 0; i < count; i++)
				fputs(temp[i], stdout);
			break;
		case '5':
			return 0;
		default:
			printf("No such option.");
		}
		while (getchar() != '\n')
			;
	}
	return 0;
}