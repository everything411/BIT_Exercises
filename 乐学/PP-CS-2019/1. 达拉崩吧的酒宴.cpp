#include <iostream>
using namespace std;
unsigned long long arr[100];
void init(void)
{
    for (int i = 0; i < 64; i++)
    {
        arr[i] = 1LL << (unsigned long long)i;
    }
}
int first_bit_pos(unsigned long long n)
{
    for (int i = 0; i < 100; i++)
    {
        if (n <= arr[i])
        {
            return i;
        }
    }
}
int main(void)
{
    int T;
    unsigned long long n;
    cin >> T;
    init();
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << first_bit_pos(n) << endl;
    }

    return 0;
}