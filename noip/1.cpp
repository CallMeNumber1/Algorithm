/*************************************************************************
	> File Name: 1.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月05日 星期六 15时37分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000

// 记忆化搜索
// 开在全局区
namespace smallData {
    int keep[MAX_N + 5] = {0, 1, 2};
    int f(int n) {
        if (keep[n]) return keep[n];
        keep[n] = f(n - 1) + f(n - 2);
        return keep[n];
    }
}

namespace bigData {
    int f[MAX_N + 5][100] = {0};
    void solve(int n) {
        f[1][0] = f[1][1] = 1;
        f[2][0] = 1, f[2][1] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= f[i - 1][0]; j++) {
                f[i][j] = f[i - 1][j] + f[i - 2][j];
            }
            f[i][0] = f[i - 1][0];
            for (int j = 1; j <= f[i][0]; j++) {
                if (f[i][j] < 10) continue;
                f[i][j + 1] += f[i][j] / 10; 
                f[i][j] %= 10;
                f[i][0] += (j == f[i][0]);
            }
        }
        for (int i = f[n][0]; i >= 1; i--) {
            cout << f[n][i];
        }
        cout << endl;
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n <= 20) {
            cout << smallData::f(n) << endl;
        } else {
            bigData::solve(n);
        }
    }
    return 0;
}
