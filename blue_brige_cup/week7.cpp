#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1005
struct Node {
    int weight;
    int value;
    Node(int w, int v) {
        weight = w;
        value = v;
    }
    Node() {}
    bool operator<(const Node &obj) const {
        if (weight == obj.weight) {
            return value > obj.value;
        } else {
            return weight < obj.weight;
        }
    }
};
int main(){
    int n;
    cin >> n;
    Node num[MAX];
    int dp[MAX];
    for (int i = 0; i < n; i++) {
        cin >> num[i].weight >> num[i].value;
    }    
    sort(num, num + n);
    for (int i = 0; i < n; i++) {
        cout << num[i].weight << " " << num[i].value << endl;
    }
    int ans = 0;
    vector<Node> temp;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        int pre = 100000;
        for (int j = 0; j < i; j++) {
            if (num[j].weight < num[i].weight && num[j].value > num[i].value && num[j]. value < pre) {
                pre = num[j].value;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 如果更大的话，更新最大值，以及存放最大值路径的数组
        if (dp[i] > ans) {
            ans = dp[i];
            int t = 1;
            temp.clear();
            int pre = 100000;
            for (int j = 0; j < i; j++) {
                if (num[j].weight < num[i].weight && num[j].value > num[i].value && num[j].value < pre) {
                    pre = num[j].value;
                    if (dp[j] + 1 > t) {
                        t = dp[j] + 1;
                        temp.push_back(Node(num[j].weight, num[j].value));
                    }
                }
            }
            temp.push_back(Node(num[i].weight, num[i].value));    
        }
    }
    cout << ans << endl;
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i].weight << " " << temp[i].value << endl;
    }
    return 0;
}
