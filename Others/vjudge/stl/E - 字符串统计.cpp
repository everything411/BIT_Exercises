#include <iostream>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    int total, i, count;
    cin >> total;
    for (i = 0; i < total; i++)
    {
        cin >> str;
        count = 0;
        for (auto &i : str)
        {

            if (isdigit(i))
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
