/*************************************************************************
	> File Name: las.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月11日 星期五 23时14分04秒
 ************************************************************************/

/*
 *最长上升子序列优化做法
  对状态转移进行优化
  增加一个len数组，记录长度为i的序列的末尾最小值
 */

#include <stdio.h>
#define MAX_N 1000000
int dp[MAX_N + 5] = {0};
int len[MAX_N + 5] = {0};
int val[MAX_N + 5] = {0};


// 寻找最后一个小于val的位置
// 二分，前1后0模型
int BinarySearch(int *len, int size, int val) {
    int head = 0, tail = size - 1;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (len[mid] < val) head = mid;     // 不能等于，因为小于时才能接在后面
        else tail = mid - 1;
    }
    return head;
}

int main() {
    int n;
    len[0] = -1;
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    
    int length = 1;
    for (int i = 1; i < n; i++) {
        int ind = BinarySearch(len, length, val[i]);
        dp[i] = ind + 1;
        len[dp[i]] = val[i];
        if (length <= dp[i]) length += 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < dp[i]) ans = dp[i];
    }

    printf("%d\n", ans);
    return 0;
}

