#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int numbers[n];
    int curr_start = 0, curr_end = 0;
    int start = 0, end = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", numbers + i);
    for (int i = 0; i < n; i++)
    {
        // fix a bound error here
        // if (i < n && numbers[i] == numbers[i + 1])
        if (i < n - 1 && numbers[i] == numbers[i + 1])
        {
            curr_start = i;
            flag = 1;
        }
        // while (i < n && numbers[i] == numbers[i + 1])
        while (i < n - 1 && numbers[i] == numbers[i + 1])
            curr_end = ++i;
        if (curr_end - curr_start > end - start)
        {
            start = curr_start;
            end = curr_end;
        }
    }
    if (flag)
        printf("The longest equal number list is from %d to %d.\n", start, end);
    else
        printf("No equal number list.\n");
    return 0;
}
