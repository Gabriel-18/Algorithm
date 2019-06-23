#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 1000; // 最大顶点数
const int INF = 1000000000; // 设为一个很大的数

int n, m, G[MAXV][MAXV];
int d[MAXV]; // 顶点与集合s最短距离
bool vis[MAXV] = {false};// 标记数组

int prime(){
    // fill函数将整个数组赋为INF
    fill(d, d + MAXV, INF);
    // 假设0号到集合S的距离为0 其余为INF
    d[0] = 0;
    // 存放最小生成树的边权之后
    int ans = 0;
    // 循环n次
    for (int i = 0; i < n; ++i) {
        // u 中介点
        // MIN 存放最小的d[u]
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的d[u] 则剩下的顶点和集合s不连通
        if (u == -1) return -1;
        // 标记u为被访问
        vis[u] = true;
        // 将与集合S距离最小的边加入最小生成树
        ans += d[u];

        for (int v = 0; v < n; ++v) {
            // v未访问 u能能到达 以u的中介点使得v离S更近
            if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}
int main() {
    int u, v, w;
    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u,&v,&w);
        G[u][v] = G[v][u] = w;
    }
    int ans = prime();
    printf("%d\n",ans);
    return 0;
}