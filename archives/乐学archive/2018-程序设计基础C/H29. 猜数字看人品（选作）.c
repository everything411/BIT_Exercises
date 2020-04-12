#include <stdio.h>
#include <limits.h>
#include <string.h>
const char *low = "too low";
const char *high = "too high";
const char *right = "right on";
const char *honest = "Tom may be honest";
const char *dishonest = "Tom is dishonest";
int main(int argc, char const *argv[])
{
    int value;
    int min, max;
    char buffer[32];
    max = INT_MAX;
    min = INT_MIN;
    while (~scanf("%d\n", &value))
    {
        if (!value)
            return 0;
        scanf("%[^\n]\n", buffer);
        if (!strcmp(buffer, low))
        {
            if (value > min)
                min = value;
        }
        else if (!strcmp(buffer, high))
        {
            if (value < max)
                max = value;
        }
        else if (!strcmp(buffer, right))
        {
            fprintf(stderr, "min %d, max %d, value %d.\n", min, max, value);
            if (min >= max || value >= max || value <= min)
                puts(dishonest);
            else
                puts(honest);
            max = INT_MAX;
            min = INT_MIN;
        }
        else
        {
            fprintf(stderr, "Invalid command\n");
            return 1;
        }
    }
    return 0;
}
