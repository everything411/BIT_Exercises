#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <functional>
using namespace std;
int main(int argc, char const *argv[])
{
    int init[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15};
    long long num;
    priority_queue<long long, vector<long long>, greater<long long> > ugly_nums_que;
    set<long long> ugly_nums_set;
    vector<long long> ugly_nums_vector;
    for (int i = 0; i < 11; i++)
    {
        ugly_nums_set.insert(init[i]);
        ugly_nums_que.push(init[i]);
    }
    while (ugly_nums_vector.size() < 1500)
    {
        num = ugly_nums_que.top();
        ugly_nums_que.pop();
        ugly_nums_vector.push_back(num);
        if (2 * num > 0 && ugly_nums_set.find(2 * num) == ugly_nums_set.end())
        {
            ugly_nums_set.insert(2 * num);
            ugly_nums_que.push(2 * num);
        }
        if (3 * num > 0 && ugly_nums_set.find(3 * num) == ugly_nums_set.end())
        {
            ugly_nums_set.insert(3 * num);
            ugly_nums_que.push(3 * num);
        }
        if (5 * num > 0 && ugly_nums_set.find(5 * num) == ugly_nums_set.end())
        {
            ugly_nums_set.insert(5 * num);
            ugly_nums_que.push(5 * num);
        }
    }
    while ((cin >> num) && num != 0)
    {
        cout << ugly_nums_vector[num - 1] << endl;
    }
    return 0;
}
