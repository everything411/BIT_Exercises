#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
    int case_count;
    string num_str;
    deque<char> ans;
    scanf("%d", &case_count);
    for (int i = 0; i < case_count; i++)
    {
        ans.clear();
        cin >> num_str;
        for (auto &i : num_str)
        {
            if (i != '0')
            {
                ans.push_front(i);
                i = 'a';
                break;
            }
            else
            {
                ans.push_front(i);
                i = 'a';
            }
        }

        for (auto i : num_str)
        {
            if (isdigit(i))
            {
                if (i == '0' || i > *ans.begin())
                {
                    ans.push_back(i);
                }
                else
                {
                    ans.push_front(i);
                }
            }
        }
        for (auto i : ans)
            cout << i;
        cout << endl;
    }

    return 0;
}
