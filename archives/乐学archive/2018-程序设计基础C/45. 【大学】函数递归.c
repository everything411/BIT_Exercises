/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW 

#include <stdio.h>

int main()
{
    int n, s, findf(int);
    scanf("%d", &n);
    s = findf(n);
    printf("%d\n", s);
    return 0;
}

 PRESET CODE END - NEVER TOUCH CODE ABOVE */
int findf(int n)
{
    if (n >= 0 && n <= 4)
        return 1;
    if (n > 4)
        if (n & 1)
            return findf(n - 2) + findf(n - 4);
        else
            return findf(n - 1) + findf(n - 3);
    return -1;
}