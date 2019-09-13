#include <iostream>
#include <algorithm>
using namespace std;

unsigned x, y, z;
unsigned rng61()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}
int main(int argc, char const *argv[])
{
    int n, m, A, B, C;
    A = B = C = 1;
    x = A, y = B, z = C;

    for (int i = 0; i < 100; i++)
    {
        cout << rng61() << endl;
    }

    return 0;
}
