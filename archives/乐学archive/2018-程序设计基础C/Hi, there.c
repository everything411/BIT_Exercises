#include <stdio.h>
char *gets(char *s);
int main(int argc, char const *argv[])
{
    char name[128];
    gets(name);
    printf("Hi,there,%s!\n", name);
    return 0;
}
