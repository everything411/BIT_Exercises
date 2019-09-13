#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const string teacher[2][3] = {{"he", "jin", "min"}, {"ma", "ze", "hang"}};
int name_found[2][3];
int main(void)
{
    string pinyin;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pinyin;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (pinyin == teacher[j][k])
                {
                    name_found[j][k] = i + 1;
                }
            }
        }
        if (name_found[0][0] && name_found[0][1] && name_found[0][2])
        {
            cout << 3 << endl;
            cout << name_found[0][0] << " " << name_found[0][1] << " " << name_found[0][2] << endl;
            return 0;
        }
        if (name_found[1][0] && name_found[1][1] && name_found[1][2])
        {
            cout << 3 << endl;
            cout << name_found[1][0] << " " << name_found[1][1] << " " << name_found[1][2] << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}