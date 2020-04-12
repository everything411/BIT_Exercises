#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int n,min = 1, max = 10, count = 0, sum = 0;
    char char_num[7];
    scanf("%d", &n);
    
    for(int i = 1; i < n; i++)
    {
        min *= 10;
        max *= 10;
    }
    
    for (int proc_num = min; proc_num < max; proc_num++)
    {
        sprintf(char_num, "%d", proc_num);
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            char_num[i] -= '0';
            sum += pow(char_num[i], n);
        }
        if(sum == proc_num)
        {
            printf("%d\n", sum);
            count++;
        }
    }
    if(count == 0)
    {
        puts("No output.");
    }
    return 0;
}
