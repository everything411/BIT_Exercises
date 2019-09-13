/* template 1004.cpp from 搜索相关课件及代码 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
struct node
{
    int x, y;
    int step;
    node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};
queue<node> que;
bool vis[maxn][maxn][50];
char mp[maxn][maxn];
void clear_queue()
{
    while (!que.empty())
    {
        que.pop();
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, m, k;
        int start_x, start_y;
        start_x = start_y = -1;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; ++j)
            {
                if (mp[i][j] == 'S')
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        que.push(node(start_x, start_y, 0));
        vis[start_x][start_y][0] = 1;
        int ans;
        while (!que.empty())
        {
            node tmp = que.front();
            que.pop();
            if (mp[tmp.x][tmp.y] == 'E')
            {
                ans = tmp.step;
                goto case_ok;
            }
            for (int i = 0; i < 4; ++i)
            {
                int x = tmp.x + dx[i];
                int y = tmp.y + dy[i];
                if ((tmp.step + 1) % k == 0) //disappear
                {
                    if (x < 0 || x >= n || y < 0 || y >= m ||
                        mp[x][y] == '#' || vis[x][y][(tmp.step + 1) % k] == 1)
                    {
                        continue;
                    }
                }
                else
                {
                    if (x < 0 || x >= n || y < 0 || y >= m ||
                        mp[x][y] == '#' || mp[x][y] == '*' || vis[x][y][(tmp.step + 1) % k] == 1)
                    {
                        continue;
                    }
                }
                que.push(node(x, y, tmp.step + 1));
                vis[x][y][(tmp.step + 1) % k] = 1;
            }
        }
        // case fail
        puts("-1");
        clear_queue();
        continue;
    case_ok:
        printf("%d\n", ans);
        clear_queue();
        continue;
    }
    return 0;
}