#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long a, b;
    while (true)
    {
        scanf("%lld%lld", &a, &b);
        if (a == -1 && b == -1)
        {
            break;
        }
        printf("%lld\n", a + b);
        fflush(stdout);
    }
    return 0;
}
