//
// Created by Kelper on 2019/6/23.
//

#include <cstdio>
const int N = 100;
int father[N]; // 存放父亲节点

bool isRoot[N]; // 记录每个节点是否作为某个节点的根节点

int findFather(int x) { // 查找x所在集合的根节点
    // x在下面会变成根节点 先保存一下
    int a = x;
    while (x != father[x]) { // 寻找根节点
        x = father[x]; // 获取自己的父节点
    }

    // 路径压缩
    while (a != father[a]) {
        int z = a;
        a = father[a]; // a回溯父亲节点
        father[z] = x; //将原先的节点a的父亲改为根节点x
    }
    return x;
}

void Union(int a, int b) { // 合并a,b所在的集合
    int faA = findFather(a);
    int faB = findFather(b);

    if (faA != faB) {
        father[faA] = faB;
    }
}

void init(int n) { // 初始化father[i] 为i 且flag为false
    for (int i = 1; i <= n ; ++i) {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    init(n);

    for (int k = 0; k < m; ++k) {
        scanf("%d%d", &a, &b);
        Union(a, b);
    }

    for (int i = 0; i <= n; ++i) {
        isRoot[findFather(i)] = true;
    }

    int ans = 0;
    for (int j = 1; j <= n ; ++j) {
        ans += isRoot[j];
    }
    printf("%d\n", ans);
    return 0;
}