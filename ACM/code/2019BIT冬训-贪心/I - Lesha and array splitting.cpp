#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int count;
    int sum = 0;
    int prev_sum = -1;
    cin >> count;
    vector<int> arr(count);
    vector<int> ans;
    for (auto &i : arr)
        cin >> i;
    ans.push_back(1);
    for (int i = 0; i < count; i++)
    {
        sum += arr[i];
        if (sum == 0 && (prev_sum != 0 || (prev_sum = -1)))
        {
            ans.push_back(i + 1);
            prev_sum = -1;
        }
        prev_sum = sum;
    }
    if (ans.size() & 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i += 2)
        {
            cout << ans[i] << ' ' << ans[i + 1] << endl;
        }
    }

    return 0;
}
