#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
    int count = 0;
    string str;
    set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    set<char> even = {'1', '3', '5', '7', '9'};
    cin >> str;
    for (auto &&i : str)
    {
        if (isdigit(i) && even.find(i) != even.end())
            count++;
        if (isalpha(i) && vowel.find(i) != vowel.end())
            count++;
    }
    cout << count << endl;
    return 0;
}
