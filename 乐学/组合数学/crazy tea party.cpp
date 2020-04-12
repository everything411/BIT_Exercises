#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ans;
        scanf("%d", &num);
        if (num & 1)
        {
            ans = (num / 2) * (num / 2 - 1) / 2 + (num / 2 + 1) * (num / 2) / 2;
        }
        else
        {
            ans = (num / 2) * (num / 2 - 1);
        }
        printf("%d\n", ans);
    }

    return 0;
}
