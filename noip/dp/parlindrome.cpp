/*************************************************************************
	> File Name: parlindrome.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月12日 星期六 17时30分53秒
 ************************************************************************/
/*
    切割回文
    当dp数组开大时，比如开5000，5000时会出现段错误，为什么
    此种做法在HZOJ上仅能通过30%样例
    猜测是TLE
    优化方案见parlindrome_opt.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500000

int main() {
    char str[MAX + 5];
    
    scanf("%s", str);
    int len = strlen(str);
    //printf("%d %s\n", len, str);
    int **dp = (int **)calloc(sizeof(int *), len);
    for (int i = 0; i < len; i++) {
        dp[i] = (int *)calloc(sizeof(int), len);
    }
    dp[0][0] = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] == str[j] && dp[i + 1][j - 1] == 0) {
                dp[i][j] = 0;
            } else {
                int min = 0x7fffffff;
                for (int k = i; k < j; k++) {
                    int temp = dp[i][k] + dp[k + 1][j] + 1;
                    if (min > temp) min = temp;
                }
                dp[i][j] = min;
            }
        }
    }

    printf("%d\n", dp[0][len - 1]);
    return 0;

}

