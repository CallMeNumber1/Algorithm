#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main(){
    // 使用优先队列保证每次最小的在队头
    priority_queue<long long, vector<long long>, greater<long long> > q;
    set<long long> s;
    long long ans = -1;
    q.push(1);
    s.insert(1);
    while (1) {
        long long n = q.top();
        q.pop();
        ans++;
        if (n == 59084709587505) break;
        for (int i = 3; i <= 7; i += 2) {
            long long t = n * i;
            if (s.find(t) == s.end()) {
                s.insert(t);
                q.push(t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
