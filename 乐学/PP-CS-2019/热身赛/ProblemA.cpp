#include <iostream>
using namespace std;
int main(void)
{
    long long a, b;
    while (~scanf("%lld%lld", &a, &b))
    {
        printf("%lld\n", a + b);
    }
    return 0;
}