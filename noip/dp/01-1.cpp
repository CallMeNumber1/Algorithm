/*************************************************************************
	> File Name: 01-1.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月06日 星期三 15时54分55秒
 ************************************************************************/
/* 01背包
 * 状态压缩版本
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
    cin >> W >> n;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}

