/*************************************************************************
	> File Name: P1044.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月09日 星期六 23时43分17秒
 ************************************************************************/
/*
 * 栈
 * 思路：很显然，对于每个合法的操作序列(如题目描述里的push,push,pop,push,pop,pop),都对应一个输出序列，于是题目就转化成了求合法操作序列数量。

    我们总结出如下规律：

    1如果栈非空，那么下一步就既可push，又可pop
    2否则，下一步只可以push。
 */

#include <iostream>
#include <string>
using namespace std;
#define MAX_N  20
// f[i][j]代表i步，栈内有j个元素时的方案数
int f[MAX_N * 2][MAX_N] = {0};
int n;

int solve(int i, int j) {
    int sum = 0;
    if (i == 2 * n) {           // 步数已满 返回
        if (j == 0) return 1;   // 所有操作完成后栈是否清空
        return 0;
    }
    if (f[i][j] != 0) return f[i][j];
    // 栈不满时就可以push操作
    if (j <= n) sum += solve(i + 1, j + 1);
    // 栈非空就可以pop操作
    if (j > 0) sum += solve(i + 1, j - 1);
    f[i][j] = sum;
    return f[i][j];
}


int main() {
    cin >> n;
    solve(0, 0);
    /*
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << f[0][0] << endl;      


    return 0;
}
