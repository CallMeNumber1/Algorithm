/*************************************************************************
	> File Name: parlindrome.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月12日 星期六 17时30分53秒
 ************************************************************************/
/*
    切割回文
    优化方案
    dp[i]代表从0到i最小切割数

    仍然过30%样例。。。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500000

char str[MAX + 5];

int isParlindrome(int l, int r) {
    while (l <= r) {
        if (str[l] != str[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    
    scanf("%s", str);
    int len = strlen(str);
    //printf("%d %s\n", len, str);
    int dp[MAX + 5] = {0}; 
    //int *dp = (int *)calloc(sizeof(int), len + 1);
    

    for (int i = 0; i < len; i++) {
        if (isParlindrome(0, i)) {
            dp[i] = 0;
        } else {
            dp[i] = i;              // 最坏的打算，即长度为i的字符串需要切割i-1次
            for (int j = 1; j < i; j++) {
                if (isParlindrome(j, i)) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);    
                }
            }
        }
    }
    
    printf("%d\n", dp[len - 1]);
    return 0;

}

