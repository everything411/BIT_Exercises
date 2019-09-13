#include <stdio.h>
int main(int argc, char const *argv[])
{
    int price, discount;
    scanf("%d%d", &price, &discount);
    printf("%.2f\n", 0.1 * price * discount);
    return 0;
}
