#include <stdio.h>
char *mystrncpy(char *restrict dst, const char *restrict src, size_t len)
{
	int i;
	for (i = 0; i < len && src[i]; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return dst;
}

int main(void)
{
	const char src1[] = "hello, world.";
	const char src2[] = "There are many characters.abcdef,123456";
	char dst[20];
	mystrncpy(dst, src1, 20);
	puts(dst);
	mystrncpy(dst, src2, 20);
	puts(dst);
	return 0;
}