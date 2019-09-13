#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long sum, tmp, count;
    sum = count = 0;
    while (~scanf("%lld", &tmp))
    {
        sum += tmp;
        count++;
    }
    count++;
    printf("%lld\n", (count + 1) * count / 2 - sum);
    return 0;
}
