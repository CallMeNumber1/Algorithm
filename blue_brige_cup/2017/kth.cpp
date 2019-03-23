/*
 求区间[l,r]的和是k的倍数的个数。求区间和我们可以通过前缀和来求出
 sum[r] - sum[l - 1]即为区间[l,r]的和，区间和为k的倍数即
 (sum[r] - sum[l-1])%k == 0 即sum[r]%k == sum[l-1]%k
 那么，我们求出每个前缀和，在求的过程中取模，两个相等的前缀和就能组成一个k倍区间
 我们可以计算完前缀和之后使用两层for循环来计数k倍区间的个数，但会超时
    因此我们就想在计算前缀和的过程中记录k倍区间的个数
    我们用一个数组num[i]表示当前位置之前，前缀和取模后等于i的个数
    这样计算后，最后还要加上前缀和取模后为0的个数即num[0]（因为我们漏掉了前i个数的和是k的倍数的情况即[0,i]区间是k的倍数）
*/

#include<iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int num[100000];                // 代表
    int sum[100000];
    long long int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        long long int a;
        cin >> a;
        sum[i] = (sum[i - 1] + a) % k;
        ans += num[sum[i]];
        num[sum[i]]++;
    }
    cout << ans + num[0] << endl;
}