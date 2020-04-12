#include <stdio.h>
int main(void)
{
    int count, value;
    int ans = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &value);
        if (value > 5)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}