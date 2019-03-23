#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 10000
vector<int> num[MAX + 5];
int main(){
    int w, m, n;
    cin >> w >> m >> n;
    int row = MAX / w;
    int x1, x2, y1, y2;
    for (int i = 1; i <= row; i++) {
        // 奇数行
        if (i % 2) {
            for (int j = (i - 1) * w + 1; j <= i * w; j++) {
                num[i].push_back(j);
            }
        } else {
            for (int j = i * w; j > (i - 1) *  w; j--) {
                num[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 0; j < num[i].size(); j++) {
            if (num[i][j] == m) x1 = i, y1 = j;
            if (num[i][j] == n) x2 = i, y2 = j;               
        }
    }
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 0; j < num[i].size(); j++) {
    //         cout << num[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}  
