/*************************************************************************
	> File Name: rectangle.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月09日 星期六 17时06分00秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000
#define MOD_NUM 100007
int f[MAX_N + 5][MAX_N + 5] = {0};
int dp[MAX_N +5][MAX_N + 5] = {0};
int s[MAX_N + 5] = {0}, top = -1;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
        f[i][m] = -1;
    }
    // 处理f数组
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 0) continue;
            f[i][j] += f[i + 1][j];
        }
    }
    int ans = 0;
    // 维护单调栈去维护每一行的dp值
    for (int i = 0; i < n; i++) {
        // 压进单调栈一个起始点,单调递增栈栈底应该是个极小值
        top = -1;
        s[++top] = m;
        for (int j = m - 1; j >= 0; j--) {
            // 找到第一个比f[i][j]小的列号
            while (f[i][s[top]] > f[i][j]) --top;
            dp[i][j] = (s[top] - j) * f[i][j] + dp[i][s[top]];
            dp[i][j] %= MOD_NUM;
            ans += dp[i][j];
            ans %= MOD_NUM;
            // 将j的列号压栈
            s[++top] = j;
        }
    }
    cout << ans << endl;;
    return 0;
}

