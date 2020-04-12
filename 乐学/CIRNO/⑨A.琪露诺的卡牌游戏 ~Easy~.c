/* Written by Whitesad */
/* Modified by everything411 */
#include <stdio.h>
int main()
{
    scanf("%*d");
    int card[10] = {0};
    int num;
    while (scanf("%d", &num) != EOF)
        card[num]++;
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += card[i] * i;
    if ((sum % 9))
        card[sum % 9]--;
    for (int i = 9; i >= 0; i--)
        for (num = 0; num < card[i]; num++)
            printf("%d", i);
    printf("\n");
}