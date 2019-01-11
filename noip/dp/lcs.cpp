/*************************************************************************
	> File Name: lcs.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月11日 星期五 23时31分10秒
 ************************************************************************/

// 最长公共子序列（序列是可以不连续的）
// dp[i][j]代表A串长i，B串长j时的最长公共子序列
#include <stdio.h>
#include <string.h>
#define MAX_N 1000
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    char s1[MAX_N + 5];
    char s2[MAX_N + 5];
    scanf("%s%s", s1, s2);
    
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[MAX_N + 5][MAX_N + 5] = {0};
    
    // 初始dp[i][0] dp[0][j]都为0
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    printf("%d\n", dp[len1][len2]);
    return 0;
}

