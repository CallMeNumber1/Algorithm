/*************************************************************************
	> File Name: 03-2.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月07日 星期四 23时24分04秒
 ************************************************************************/
/* 多重背包
 * 单调队列优化
 */

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100
#define MAX_V 100000
int dp[MAX_N + 5][MAX_V + 5] = {0};
int v[MAX_N + 5], w[MAX_N + 5], s[MAX_N + 5];
// 定义单调队列
struct Data{
    int val, j;             // val值和重量值
} q[MAX_V + 5];
int head, tail;

int main() {
    int n, V;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++) {
        // ｒ即为余数系
        for (int r = 0; r < v[i]; r++) {
            head = 0, tail = 0;
            q[tail++] = {dp[i - 1][r], r};
            dp[i][r] = dp[i - 1][r];
            // j为背包重量
            for (int j = r + v[i]; j <= V; j += v[i]) {
                int val = dp[i - 1][j] - j / v[i] * w[i];
                // 如果大于尾部值，则将尾部元素出队
                while (head < tail && val >= q[tail - 1].val) --tail;
                q[tail++] = {val, j};
                // 判断头部元素是否出队
                // 即超过第ｉ种物品的数量时
                if ((j - q[head].j) / v[i] > s[i]) ++head;
                dp[i][j] = q[head].val + j / v[i] * w[i];
            }
        }
    }
    cout << dp[n][V] << endl;
    return 0;
}

