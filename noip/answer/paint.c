/*************************************************************************

 > Author:    hug

 > Problem:   动态规划-练习题：墙壁涂色

 > Mail:      hug@haizeix.com

 ************************************************************************/

 
#include <stdio.h>
long long f[2][3][3];

 

long long paintWallCounts(int wallsize) {

    int i, j, k, l;

    if (wallsize == 1) return 3;

    for (i = 0; i < 3; ++i) {

        for (j = 0; j < 3; ++j) {

            if (i == j) continue;

            f[0][i][j] = 1;

        }

    }

    for (i = 3; i <= wallsize; ++i) {

        for (j = 0; j < 3; ++j) {

            for (k = 0; k < 3; ++k) {

                f[i % 2][k][j] = 0;

                for (l = 0; l < 3; ++l) {

                    if (l == j) continue;

                    f[i % 2][k][j] += f[(i % 2) ^ 1][k][l];

                }

            }

        }

    }

    long long ans = 0;

    for (i = 0; i < 3; ++i) {

        for (j = 0; j < 3; ++j) {

            if (i == j) continue;

            ans += f[wallsize % 2][i][j];

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

