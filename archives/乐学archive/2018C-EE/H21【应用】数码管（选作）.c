/**
 *  　2
 *  +---+
 * 3| 　|4
 *  | 1 |
 *  +---+
 * 5| 　|6
 *  | 0 |
 *  +---+ 
**/
/**
 * 0 0111 1101 -> 7D
 * 1 0101 0000 -> 50
 * 2 0011 0111 -> 37
 * 3 0101 0111 -> 57
 * 4 0101 1010 -> 5A
 * 5 0100 1111 -> 4F
 * 6 0110 1111 -> 6F
 * 7 0101 0100 -> 54
 * 8 0111 1111 -> 7F
 * 9 0101 1111 -> 5F
**/
#include <stdio.h>
char *ctrl_hex[10] = {"7D", "50", "37", "57", "5A", "4F", "6F", "54", "7F", "5F"};
int main(int argc, char const *argv[])
{
    int number_int;
    char number[16];
    while (scanf("%d", &number_int) && number_int)
    {
        sprintf(number, "%05d", number_int);
        for (int i = 0; i < 5; i++)
        {
            printf(i == 4 ? "%s\n" : "%s ", ctrl_hex[number[i] - '0']);
        }
    }
    return 0;
}
