#include <stdio.h>
int main(int argc, char const *argv[])
{
    int day;
    int peach = 1;
    scanf("%d", &day);
    while (day-- > 1)
    {
        peach += day;
        peach *= 2;
    }
    printf("The monkey got %d %s in first day.\n", peach, peach == 1 ? "peach" : "peaches");
    return 0;
}
