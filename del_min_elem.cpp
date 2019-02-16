/*************************************************************************
	> File Name: del_min_elem.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年02月16日 星期六 23时15分32秒
 ************************************************************************/

/* 求职算法辅导
 * 动态规划
 * 删除最少的元素
 */

#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int countDeletedElements(int *nums, int length) {
	#define MAX 1005
    int f1[MAX] = {0}, f2[MAX] = {0};
    // 从前往后找每一位上的最长非递增子序列
	for (int i = 0; i < length; i++) {
        f1[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] >= nums[i]) {
                f1[i] = max(f1[i], f1[j] + 1);
            }
        }
    }
    // 从后往前找每一位上的最长非递增子序列
    for (int i = length - 1; i >= 0; i--) {
		f2[i] = 1;
        for (int j = length - 1; j > i; j--) {
            if (nums[j] >= nums[i]) {
                f2[i] = max(f2[i], f2[j] + 1);
            }
        }
    }
    // 找到符号要求的序列最大值
    int ans = 0;
    for (int i = 0; i < length; i++) {
        if (ans < f1[i] + f2[i] - 1) ans = f1[i] + f2[i] - 1;
    }
    return length - ans;
    // 求出最少删除的元素数
}
int main() {
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", countDeletedElements(a, n));
	return 0;
}
