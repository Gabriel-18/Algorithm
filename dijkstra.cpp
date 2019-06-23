//
// Created by Kelper on 2019/6/22.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 1000; // 最大顶点数
const int INF = 1000000000; // 设为一个很大的数

// n为顶点数 m为边数 s为起点
int n, m, s,G[MAXV][MAXV];
int d[MAXV]; // 起点到各点的最短路径长度
bool vis[MAXV] = {false};// 标记数组

void Dijkstra(int s){
    // fill函数将整个数组赋为INF
    fill(d, d + MAXV, INF);
    // 假设s到达自身距离为0
    d[s] = 0;
    // 循环n次
    for (int i = 0; i < n; ++i) {
        // u 中介点
        // MIN 存放最小的d[u]
        int u = -1, MIN = INF;
        // 找到未访问的顶点中d[] 最小的
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的d[u] 则剩下的顶点和起点s不连通
        if (u == -1) return ;
        // 标记u为被访问
        vis[u] = true;


        for (int v = 0; v < n; ++v) {
            // v未访问 u能能到达 以u的中介点使得v离S更近
            if (vis[v] == false && G[u][v] != INF && G[u][v] + d[u] < d[v]) {
                d[v] = G[u][v] + d[u];
            }
        }
    }
}
int main() {
    int u, v, w;
    // 顶点个数 边数 起点编号
    scanf("%d%d%d", &n, &m, &s);
    // 初始化图
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 0; i < m; ++i) {
        // 输入u,v 以及u,v 的边权
        scanf("%d%d%d", &u,&v,&w);
        G[u][v] = w;
    }
    Dijkstra(s);
    for (int j = 0; j < n; ++j) {
        printf("%d ", d[j]);
    }
    return 0;
}