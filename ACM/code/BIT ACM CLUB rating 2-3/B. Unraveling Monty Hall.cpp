#include <iostream>
int main(int argc, char const *argv[])
{
    int n;
    int tmp;
    int times = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (tmp != 1)
        {
            times++;
        }
    }
    printf("%d\n", times);
    return 0;
}
