#include <stdio.h>
int main(int argc, char const *argv[])
{
    char a = getchar();
    printf("%c\n",
           ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
               ? ((a >= 'A' && a <= 'Z') ? (a - 'A' + 'a') : (a - 'a' + 'A'))
               : a);
    return 0;
}
