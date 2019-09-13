#include <stdio.h>
#include <string.h>
using namespace std;

// 假设是一个n个点，点的下标为0 ~ n - 1，m条边的稀疏、双向图，同时规定最多不超过1000个点
// 这份代码展示使用链式前向星的建图过程
const int maxn = 1e3 + 5;
struct edge {
    // 由于next和c++关键字有冲突，故一般使用nxt表示
    int v, w, nxt;
} e[maxn << 1];
int head[maxn];

void output(int n) {
    for (int i = 0; i < n; ++i) {
        printf("#%d:", i);
        for (int idx = head[i]; idx != -1; idx = e[idx].nxt) {
            printf("edge#%d (%d -> %d) ", idx, i, e[idx].v);
            if (e[idx].nxt != -1) {
                printf(" ----> ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    // 初始化，head均为-1表示链表结束符，未连接任何边
    memset(head, -1 ,sizeof(head));
    int idx = 0;

    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        e[idx].v = v;
        e[idx].w = w;
        // 将nxt指针指向上一条边
        e[idx].nxt = head[u];
        // 将head指针指向这一条边
        head[u] = idx++;
        output(n);
    }

    return 0;
}

// 4 7
// 0 1 2
// 0 2 3
// 1 2 3
// 1 0 2
// 1 3 3
// 2 1 1
// 2 3 4
