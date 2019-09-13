#include <stdio.h>
#include <string.h>
void char_reverse(char *arr);
int main(void)
{
	char source[128];
	while (fgets(source, 128, stdin))
	{
		char_reverse(source);
		fputs(source, stdout);
	}
	return 0;
}
void char_reverse(char *arr)
{
	int len = strlen(arr);
	char temp[len];
	for (int i = 0; i < len; i++)
		temp[len - i - 1] = arr[i];
	for (int i = 0; i < len; i++)
		arr[i] = temp[i];
}