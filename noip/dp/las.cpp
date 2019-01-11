/*************************************************************************
	> File Name: las.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月11日 星期五 23时14分04秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 500000

int main() {
    int n;
    int dp[MAX_N + 5] = {0};
    int val[MAX_N + 5] = {0};
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    for (int i = 1; i < n; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (val[j] >= val[i]) continue;
            int temp = dp[j];
            if (temp > max) max = temp;
        } 
        dp[i] = max + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < dp[i]) ans = dp[i];
    }

    printf("%d\n", ans);
    return 0;
}

