/* template 1004.cpp from 搜索相关课件及代码 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
struct node
{
    int x, y;
    int step;
    node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};
queue<node> que;
bool vis[maxn][maxn];
char mp[maxn][maxn];

int main(void)
{
    int n, m, k;
    int start_x, start_y;
    int end_x, end_y;
    int ans;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", mp[i]);
    }
    scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
    memset(vis, 0, sizeof(vis));
    que.push(node(start_x - 1, start_y - 1, 0));
    vis[start_x - 1][start_y - 1] = true;
    while (!que.empty())
    {
        node front_node = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 1; j <= k; j++)
            {
                int x = front_node.x + dx[i] * j;
                int y = front_node.y + dy[i] * j;
                if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#')
                {
                    break;
                }
                if (vis[x][y] == true)
                {
                    continue;
                }
                if (x == end_x - 1 && y == end_y - 1)
                {
                    ans = front_node.step + 1;
                    goto case_ok;
                }
                que.push(node(x, y, front_node.step + 1));
                vis[x][y] = true;
            }
        }
    }
    // case_fail
    puts("-1");
    return 0;
case_ok:
    printf("%d\n", ans);
    return 0;
}
