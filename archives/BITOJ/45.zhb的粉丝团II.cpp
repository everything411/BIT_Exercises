#include <iostream>
#include <algorithm>
using namespace std;
int num[10000010];
int main(int argc, char const *argv[])
{
    int n;
    int k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", num + i);
    }
    scanf("%d", &k);
    nth_element(num + 0, num + k - 1, num + n);
    printf("%d\n", num[k - 1]);
    return 0;
}
