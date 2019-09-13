#include <iostream>
using namespace std;
const double PI = 3.14;
double r, h, v;
void input(void)
{
    cin >> r >> h;
}
void calc(void)
{
    v = r * r * PI * h;
}
void output(void)
{
    cout << "v=" << v << endl;
}

int main(int argc, char const *argv[])
{
    input();
    calc();
    output();
    return 0;
}
