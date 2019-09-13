#include <cstdio>
#include <vector>
using namespace std;

// 假设是一个n个点，点的下标为0 ~ n - 1，m条边的稀疏、双向图，同时规定最多不超过1000个点
// 这份代码展示在c++11标准下的建图过程
// 即在乐学上g++4.8的方法
const int maxn = 1e3 + 5;
int main() {
    vector< pair<int, int> > vec[maxn];
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v, w;
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, w));
    }

    // 输出结果，展示如何访问这张图
    for (int i = 0; i < n; ++i) {
        for (auto &v : vec[i]) {
            printf("#%d --> #%d : %d\n", i, v.first, v.second);
        }
    }
}

// 思考：auto &v的真实变量类型是什么？
// 课后作业：了解 迭代器 相关的知识
