/*
    存储邻接矩阵可以使用一个vector数组（这样动态开辟空间不必担心空间超限）
    本题思路：
    在输入边的同时，用并查集判断当前两点是否已经连通，如果已经连通，则两点一定在环上，并且边也是在环上的。
    那么以这两个点分别作为起点和终点，用dfs找到起点到终点的路径，这条路径上的所有点就是环上的点
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000+5;
int par[maxn], vis[maxn], ret[maxn];
vector<int> edge[maxn];
int n, s, f;

int findRoot(int x) {
    return par[x] == x ? x : par[x] = findRoot(par[x]);
}

void dfs(int u, int ind) {
    ret[ind] = u;
    if(u == f) {
        sort(ret, ret + ind + 1);
        for(int i = 0; i <= ind; i++) {
            printf("%d%c", ret[i], i==ind?'\n':' ');
        }
        return;
    }
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if(!vis[v]) dfs(v, ind+1);
    }
    vis[u] = 0;
}

int main() {
    while(scanf("%d", &n) == 1) {
        int u, v;
        for(int i = 1; i <= n; i++) par[i] = i;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &u, &v);
            int ru = findRoot(u), rv = findRoot(v);
            if(ru == rv) s = u, f = v;
            else {
                par[ru] = rv;
                edge[u].push_back(v);
                edge[v].push_back(u);
            }
        }
        memset(vis, 0, sizeof(vis));
        dfs(s, 0);
    }
    return 0;
}