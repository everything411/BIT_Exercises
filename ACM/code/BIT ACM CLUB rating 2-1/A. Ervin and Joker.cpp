#include <iostream>
using namespace std;
int main(void)
{
    int total, limit;
    cin >> total >> limit;
    if (total == 0 || (limit == 1 && total % 2 == 0))
    {
        cout << "Joker" << endl;
    }
    else
    {
        cout << "Ervin" << endl;
    }
    return 0;
}
