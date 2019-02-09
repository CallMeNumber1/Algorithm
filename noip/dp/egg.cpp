/*************************************************************************
	> File Name: egg.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月08日 星期五 23时38分01秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 32
#define MAX_K 100000
typedef long long lint;
lint dp[MAX_N + 6][MAX_K + 5] = {0};

int main() {
    lint n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }
    for (int i = 1; i <= MAX_K; i++) dp[1][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= MAX_K; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] + 1;
            // +0代表要加上测k这一层
        }
    }
    lint ans = 0;
    while (dp[n][ans] < m) ans++;
    cout << ans << endl;
    return 0;
}

