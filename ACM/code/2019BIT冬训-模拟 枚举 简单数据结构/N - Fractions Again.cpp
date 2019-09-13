#include <iostream>
#include <algorithm>
using namespace std;
int ans[10000];
int main(int argc, char const *argv[])
{
    int k;
    int count;
    while (~scanf("%d", &k))
    {
        count = 0;
        for (int j = k + 1; j <= 2 * k; j++)
            if (k * j % (j - k) == 0)
                ans[count * 2] = k * j / (j - k), ans[count * 2 + 1] = j, count++;
        printf("%d\n", count);
        for (int i = 0; i < count; i++)
            printf("1/%d = 1/%d + 1/%d\n", k, ans[i * 2], ans[i * 2 + 1]);
    }
    return 0;
}
