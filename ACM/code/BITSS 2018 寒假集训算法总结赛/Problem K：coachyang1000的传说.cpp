#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main(int argc, char const *argv[])
{
    int problem_count;
    int problem_val;
    int ans = 0;
    map<string, vector<int>> problem_map;
    set<string> name_set;
    string name_buf;
    while (cin >> problem_count)
    {
        ans = 0;
        problem_map.clear();
        name_set.clear();
        for (int i = 0; i < problem_count; i++)
        {
            cin >> name_buf >> problem_val;
            if (name_set.find(name_buf) == name_set.end())
            {
                name_set.insert(name_buf);
                problem_map[name_buf].push_back(problem_val);
            }
            else
            {
                problem_map[name_buf].push_back(problem_val);
            }
        }
        for (auto &&i : name_set)
        {
            if (problem_map[i].size() <= 5)
            {
                for (auto &&j : problem_map[i])
                {
                    ans += j;
                }
            }
            else
            {
                sort(problem_map[i].begin(), problem_map[i].end(), cmp);
                for (int j = 0; j < 5; j++)
                {
                    ans += problem_map[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
