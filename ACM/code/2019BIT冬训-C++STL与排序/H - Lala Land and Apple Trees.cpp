#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct tree_t
{
    int position;
    int apple_number;
};
bool operator<(tree_t a, tree_t b)
{
    return abs(a.position) < abs(b.position);
}
vector<tree_t> left_trees, right_trees;
tree_t origin = {0, 0};
tree_t tmp_tree;
int main(int argc, char const *argv[])
{
    int count;
    int ans = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp_tree.position >> tmp_tree.apple_number;
        if (tmp_tree.position > 0)
            right_trees.push_back(tmp_tree);
        else
            left_trees.push_back(tmp_tree);
    }
    int right_size = right_trees.size();
    int left_size = left_trees.size();
    sort(right_trees.begin(), right_trees.end());
    sort(left_trees.begin(), left_trees.end());
    if (right_size > left_size)
    {
        ans += right_trees[0].apple_number;
        for (int i = 0; i < left_size; i++)
            ans += left_trees[i].apple_number + right_trees[i + 1].apple_number;
    }
    else if (right_size == left_size)
    {
        for (int i = 0; i < left_size; i++)
            ans += left_trees[i].apple_number + right_trees[i].apple_number;
    }
    else
    {
        ans += left_trees[0].apple_number;
        for (int i = 0; i < right_size; i++)
            ans += left_trees[i + 1].apple_number + right_trees[i].apple_number;
    }
    cout << ans << endl;
    return 0;
}