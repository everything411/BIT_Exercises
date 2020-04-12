#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define LEN 10240
#define LINE_LEN 128
int main(void)
{
	char data[LEN];
	char line[LINE_LEN];
	*data = '\0';
	while (fgets(line, LINE_LEN, stdin))
		strcat(data, line);
	size_t len = strlen(data);
	bool inword = false;
	int uppercase, lowercase, punctuation, digits, words;
	uppercase = lowercase = punctuation = digits = words = 0;
	for (int i = 0; i < len; i++)
	{
		if (isupper(data[i]))
			uppercase++;
		if (isdigit(data[i]))
			digits++;
		if (islower(data[i]))
			lowercase++;
		if (ispunct(data[i]))
			punctuation++;
		if (!isspace(data[i]) && !inword)
		{
			inword = true;
			words++;
		}
		if (isspace(data[i]) && inword)
			inword = false;
	}
	printf(
		"The number of words is %d.\n"
		"The number of uppercase letters is %d.\n"
		"The number of lowercase letters is %d.\n"
		"The number of punctuation characters is %d.\n"
		"The number of digits is %d.\n",
		words, uppercase, lowercase, punctuation, digits);

	return 0;
}