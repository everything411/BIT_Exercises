#include <stdio.h>
int main(void)
{
    int len, start, end;
    scanf("%d%d%d", &len, &start, &end);
    for (int i = start; i <= end; i++)
    {
        printf("%0*d\n", len, i);
    }
    return 0;
}
