#include <stdio.h>
int main()
{
    int max_weight, curr_weight, curr_pos, max_pos;
    max_weight = curr_pos = 0;
    while (scanf("%d", &curr_weight) != EOF)
    {
        curr_pos++;
        if (curr_weight > max_weight)
        {
            max_weight = curr_weight;
            max_pos = curr_pos;
        }
    }

    printf("The greatest Pikachu weights %d,its position is %d from the left to the right.\n",
           max_weight, max_pos);
    return 0;
}