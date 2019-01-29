/*************************************************************************
	> File Name: parlindrome_opt2.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2019年01月23日 星期三 00时04分29秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 500000
int dp[MAX + 5] = {0};      // dp[i] = min(dp[k] + 1) 其中s[k+1,i]是回文串
vector<int> f[MAX + 5];     // f[i]表示以i为结尾的回文串的起始位置

void expand(string s, int i, int j) {                    // 传递参数时以引用形式传递，会节省大量时间（节省拷贝时间）!!!!!!!!!!
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        f[j].push_back(i);
        i--; j++;
    }
}
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        expand(s, i, i);
        expand(s, i, i + 1);
    }
    for (int i = 0; i < s.size(); i++) {
        dp[i] = s.size();                                       // 当前位置切割次数最坏情况
        for (int k = 0; k < f[i].size(); k++) {
            int ind = f[i][k];                                  // s[ind,i]是回文串
            int val = (ind - 1 < 0 ? -1 : dp[ind - 1]);         // 当ind<1即ind=0时 取值为-1
            dp[i] = min(dp[i], val + 1);                        // dp[ind - 1]的值加上再ind-1位置切的一刀
        }
    }
    cout << dp[s.size() - 1] << endl;
    return 0;
}

