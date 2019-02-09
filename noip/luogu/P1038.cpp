/*************************************************************************
	> File Name: P1038.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月09日 星期六 22时14分23秒
 ************************************************************************/
/*
 * 神经网络
 * 拓扑排序
 */

#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX_N 105
#define MAX_M 10005
typedef struct Edge {
    int to, w, next;
} Edge;
int head[MAX_N], c[MAX_N], u[MAX_N], cnt = 0;
int in[MAX_N], out[MAX_N]; 
Edge g[MAX_M];

void add(int i, int j, int w) {
    g[++cnt].to = j;
    g[cnt].next = head[i];
    g[cnt].w = w;
    in[j] += 1;
    out[i] += 1;
    head[i] = cnt;
    return ;
}

void topsort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i]) continue;
        q.push(i);
    }
    while (!q.empty()) {
        int ind = q.front();
        q.pop();
        for (int i = head[ind]; i; i = g[i].next) {
            int to = g[i].to, w = g[i].w;
            in[to]--;
            if (c[ind] > 0) {
                c[to] += w * c[ind];
            }
            if (in[to]) continue;
            q.push(to);
        }
    }
    return ;
}

int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        // 对公式进行预处理
        // 非输入层的神经元时
        if (c[i] == 0) c[i] -= u[i];
    }
    for (int i = 1; i <= p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    topsort(n);
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        if (out[i] != 0) continue;
        if (c[i] <= 0) continue;
        cout << i << " " << c[i]<< endl;
        // 只要有输出 就把flag置0
        flag = 0;
    }
    if (flag) cout << "NULL" << endl;

    return 0;
}
