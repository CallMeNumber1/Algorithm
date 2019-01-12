/*************************************************************************
	> File Name: 01.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月12日 星期六 20时45分36秒
 ************************************************************************/

/*
 * 完全背包
 * dp[i][j]代表前i种物品，重量为j时的最大价值
 * 要注意每件物品可装多次
 * 与01背包区别：状态转移
*/
#include <stdio.h>
#define MAX_N 10005
#define MAX_V 10005


int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_V] = {0};

int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int V, n;
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            if (j < w[i]) continue;
            dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }
    
    printf("%d\n", dp[n][V]);
    return 0;
}




