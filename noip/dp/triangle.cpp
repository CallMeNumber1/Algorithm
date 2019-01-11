/*************************************************************************
	> File Name: triangle.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月11日 星期五 22时30分05秒
************************************************************************/

// 数字三角形

#include <stdio.h>
#include <math.h>
#define MAX_N 1000
 
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n;
    int dp[MAX_N + 5][MAX_N + 5] = {0};
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &dp[i][j]);   
        }
    }

    // 从下往上做时，j坐标不会超界限
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // 当从上往下做时，要判断j是否超界
    printf("%d\n", dp[1][1]);
    return 0;
}
