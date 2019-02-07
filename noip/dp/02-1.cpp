/*************************************************************************
	> File Name: 02-1.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月06日 星期三 23时56分21秒
 ************************************************************************/
/*
 * 多重背包
 * 降维版本
 */
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100
#define MAX_W 10000
int dp[MAX_W] = {0};
int v[MAX_N], w[MAX_N];
int W, n;
    
int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    
    for (int i = 0; i < n; i++) {
        // 相对于０１背包的优化，只是改变了方向
        for (int j = 1; j <= W; j++) {
            if (j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}

