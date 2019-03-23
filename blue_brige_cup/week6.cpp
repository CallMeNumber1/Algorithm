#include <iostream>
#include <algorithm>
using namespace std;
int num[105];
int main(){
    int n, p, q, k;
    cin >> n >> p >> q >> k;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    int ans = 0;
    // 没有括号的情况
    if (k == 0) {
        for (int i = n - 1; i >= n - 1 - p; i--) {
            ans += num[i];
        }
        for (int i = n - p - 2; i >= 0; i--) {
            ans -= num[i];
        }
    } else {
        ans -= num[0];
        for (int i = n - 1; i > 0; i--) {
            ans += num[i];
        }
    }
    cout << ans << endl;
    return 0;
}
