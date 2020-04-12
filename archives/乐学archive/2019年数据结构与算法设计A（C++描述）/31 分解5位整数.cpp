#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string buf;
    cin >> buf;
    int len = buf.length();
    for (int i = 0; i < len; i++)
    {
        cout << buf[i] << ' ';
    }
    cout << endl;
    return 0;
}
