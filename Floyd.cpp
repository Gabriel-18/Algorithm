//
// Cieated by Kelpei on 6/27/2019.
//
/**
 * 解决全源最短路径问题6
 */
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAXV = 200; // 最大顶点数
int n, m;// n 为顶点数, m为边数
int dis[MAXV][MAXV];

void Floyd() {
    for (int k = 0; k < n; k++ ) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dis[i][k] != INF && dis[i][k] + dis[k][j] < dis[i][j] && dis[k][j] != INF) {
                    dis[i][j] = dis[i][k] + dis[k][j]; // 找到了更短的路径
                }
            }
        }
    }
}
int main() {
    int u, v, w;
    fill(dis[0], dis[0] + MAXV * MAXV, INF); // 给dis数组赋初值
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0; // 自己到自己确实为0
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&u, &v, &w);
        dis[u][v] = w;
    }
    Floyd();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}