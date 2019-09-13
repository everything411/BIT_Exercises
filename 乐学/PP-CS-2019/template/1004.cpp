#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct node {
    int x, y;
    int step;
    // 初始化列表
    node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};
queue<node> que;
int vis[maxn][maxn];
char mp[maxn][maxn];

int main() {
    int n, m;
    int start_x, start_y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", &mp[i]);
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    // 又是一套初始化
    memset(vis, 0, sizeof(vis));
    que.push(node(start_x, start_y, 0));
    vis[start_x][start_y] = 1;
    int ans;

    while (!que.empty()) {
        node tmp = que.front();
        que.pop();

        if (mp[tmp.x][tmp.y] == 'F') {
            ans = tmp.step;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int x = tmp.x + dx[i], y = tmp.y + dy[i];

            // 不继续的条件：
            // 1 越界
            // 2 题目给出的违法条件
            // 3 访问过
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' || vis[x][y] == 1) {
                continue;
            }
            que.push(node(x, y, tmp.step + 1));
            vis[x][y] = 1;
        }
    }    
    printf("%d\n", ans);

    return 0;
}

// 7 7
// ...#...
// .....#F
// .......
// .#.#...
// .......
// .S#..#.
// .......