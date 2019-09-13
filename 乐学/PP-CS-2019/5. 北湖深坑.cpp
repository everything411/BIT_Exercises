#include <iostream>
using namespace std;
int height[100010];
int main(void)
{
    long long water;
    int highest = 0;
    int high_pos;
    int T;
    int n;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        water = 0;
        highest = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", height + i);
            if (highest < height[i])
            {
                highest = height[i];
                high_pos = i;
            }
        }
        highest = 0;
        for (int i = 0; i < high_pos; i++) // left: left -> right
        {
            if (highest < height[i])
            {
                highest = height[i];
            }
            water += highest - height[i];
        }
        highest = 0;
        for (int i = n - 1; i > high_pos; i--) // right: right -> left
        {
            if (highest < height[i])
            {
                highest = height[i];
            }
            water += highest - height[i];
        }
        cout << water << endl;
    }

    return 0;
}
