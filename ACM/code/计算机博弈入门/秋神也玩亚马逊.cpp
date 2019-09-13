#include <iostream>
#include <string>
using namespace std;
string map[10];
bool get(void)
{
    bool ret = 1;
    for (int i = 0; i < 10; i++)
        ret = ret && (cin >> map[i]);
    return ret;
}
int main(int argc, char const *argv[])
{

    while (get())
    {
        /* code */
    }

    return 0;
}
