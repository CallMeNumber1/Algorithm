/*************************************************************************
	> File Name: 03_opt.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月31日 星期四 00时07分58秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100
#define MAX_V 100000
int dp[MAX_V + 5] = {0};
int v[MAX_N + 5], w[MAX_N + 5], s[MAX_N + 5];

int n, V;

int main() {
    cin >> V >> n;
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> s[i];
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= s[i]; k <<= 1) {
            // 当前剩余商品数量
            int K = (s[i] - k + 1 < k ? s[i] - k + 1 : k); 
            // 当前体积
            int vv = v[i] * K, ww = w[i] * K;
            for (int j = V; j >= vv; j--) {
                dp[j] = max(dp[j], dp[j - vv] + ww);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
