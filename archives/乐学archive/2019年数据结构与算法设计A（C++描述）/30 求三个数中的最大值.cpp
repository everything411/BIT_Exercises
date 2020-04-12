#include <iostream>
#include <algorithm>
int nums[3];
using namespace std;
int main(int argc, char const *argv[])
{
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums, nums + 3);
    cout << "Maximum:" << nums[2] << endl;
    return 0;
}
