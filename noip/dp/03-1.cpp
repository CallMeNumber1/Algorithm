/*************************************************************************
	> File Name: 03-1.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月06日 星期三 15时40分58秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100
#define MAX_V 100000

/* 多重背包二进制优化
 * 仍然是当成０１背包做，只不过拆分方法不同了
 * 未理解第33行的意思
*/
int dp[MAX_V + 5] = {0};
int v[MAX_N + 5], w[MAX_N + 5], s[MAX_N + 5];
int n, V;

int main() {
    cin >> V >> n;
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> s[i];
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= s[i]; k <<= 1) {
            // left为物品剩余的数量，Ｋ为当前取的数量
            int left = s[i] - (k - 1);
            int K = (left < k ? left : k);
            // 当前拆分出的物品质量、价值
            int vv = v[i] * K, ww = w[i] * K;
            for (int j = V; j >= vv; j--) {
                dp[j] = max(dp[j], dp[j - vv] + ww);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}

