#include <iostream>
using namespace std;
int map[21][21];
int end_x, end_y;
int dfs(int x, int y)
{
    if (x < 1 || x > end_x || y < 1 || y > end_y)
        return 0;
    else
    {
        if (map[x][y] == 0)
            map[x][y] += dfs(x - 1, y - 2) + dfs(x - 2, y - 1) + dfs(x + 1, y - 2) + dfs(x + 2, y - 1);
        return map[x][y];
    }
}
int main(int argc, char const *argv[])
{
    cin >> end_x >> end_y;
    map[1][1] = 1;
    cout << dfs(end_x, end_y) << endl;
    return 0;
}
