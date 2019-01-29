/*************************************************************************
	> File Name: 03.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月29日 星期二 23时20分13秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100
#define MAX_W 100000

// 多重背包
// f[i][j] = max(f[i - 1][j], f[i - 1][j - k * w[i]] + k * v[i])

int dp[MAX_N + 5][MAX_W + 5] = {0};
int w[MAX_N + 5], v[MAX_N + 5], s[MAX_N + 5];

int main() {
    int W, n;
    cin >> W >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];                                // 不拿第i件
            for (int k = 1; k <= s[i]; k++) {                       // 拿上第i件
                if (k * w[i] > j) break;
                int temp = dp[i - 1][j - k * w[i]] + k * v[i];  
                if (temp > dp[i][j]) dp[i][j] = temp;
            }
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}

