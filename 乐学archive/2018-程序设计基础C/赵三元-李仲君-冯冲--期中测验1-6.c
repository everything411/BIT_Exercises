/*
Compile with gcc 4.8
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    int ret_val;
    while (ret_val = scanf("%d", &num), 1)
        switch (ret_val)
        {
        case 1:
            printf("%d", num * 3);
            break;
        case 0:
            putchar(getchar());
            break;
        case EOF:
            putchar('\n');
            return 0;
        }
}
