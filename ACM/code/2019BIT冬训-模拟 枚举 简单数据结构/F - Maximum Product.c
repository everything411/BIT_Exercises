#include <stdio.h>

int arr[20];
int main(int argc, char const *argv[])
{
    int count;
    long long case_count = 0;
    long long ans;
    while (scanf("%d", &count) != EOF)
    {
        ans = 0;
        for (int i = 0; i < count; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < count; i++)
        {
            for (int j = i; j < count; j++)
            {
                long long m = 1;
                for (int k = i; k <= j; k++)
                {
                    m = m * arr[k];
                }
                if (m > ans)
                    ans = m;
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n", ++case_count, ans);
    }
    return 0;
}