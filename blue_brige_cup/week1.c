/*************************************************************************
	> File Name: week1.c
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月10日 星期四 23时06分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000000

int keep[MAX_N * 3 + 5] = {0};

int getLength(int n) {
    if (n == 1) return 1;
    int temp;
    if (n % 2) {
        if (keep[3 * n + 1]) return keep[3 * n + 1];
        temp = getLength(3 * n + 1) + 1;
    } else {
        if (keep[n / 2]) return keep[n / 2];
        temp = getLength(n / 2) + 1;
    }
    return temp;
}



int main() {
    int i, j;
    scanf("%d%d", &i, &j);
    int ans = 0;
    int k;
    for (k = i; k <= j; k++) {
        int temp = getLength(k);
        if (temp > ans) ans = temp;
    }
    printf("%d %d %d\n", i, j, ans);
    return 0;
}

