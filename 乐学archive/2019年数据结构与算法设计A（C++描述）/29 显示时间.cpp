#include <iostream>
using namespace std;
int hour, minute, second;
void settime(void)
{
    cin >> hour >> minute >> second;
}
void show(void)
{
    cout << hour << ':' << minute << ':' << second << endl;
}
int main(int argc, char const *argv[])
{
    settime();
    show();
    return 0;
}
