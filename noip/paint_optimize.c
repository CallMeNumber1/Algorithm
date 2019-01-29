/*************************************************************************
	> File Name: paint.c
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月06日 星期日 12时54分02秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COLOR 3
#define MAX 1000    // 优化 开个滚动数组即可
// 由于递推时只需要用到前一组数据，因此数组长度为2即可

// f[n][i][j]代表前n块墙壁，在不考虑头尾成环的前提下，第1块涂i，第
// n块涂颜色j的方法总数
// 由于墙壁是环形，因此最后累加合法的方案
long long paintWallCounts(int wallsize) {
    if (wallsize == 1) return 3;
    int n = wallsize;
    long long ans = 0;
    long long f[2][COLOR][COLOR] = {0};
    // 定义初值 f[2]
    for (int i = 0; i < COLOR; i++) {
        for (int j = 0; j < COLOR; j++) {
            if (i == j) continue;
            f[0][i][j] = 1;
        }
    }
    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < COLOR; i++) {
            for (int j = 0; j < COLOR; j++) {
                // 累加之前要置0，因为保存了之前的结果
                f[k % 2][i][j] = 0;
                for (int m = 0; m < COLOR; m++) {
                    if (m == j) continue;
                    f[k % 2][i][j] += f[(k - 1) % 2][i][m];
                }
            }
        }
    }


    // 累加方案总数，i和j不能相等（不合法）
    for (int i = 0; i < COLOR; i++) {
        for (int j = 0; j < COLOR; j++) {
            if (i == j) continue;
            ans += f[n % 2][i][j];
        }   
    }
    return ans;

}


int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", paintWallCounts(n));
    
    return 0;
}

