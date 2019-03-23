/*
    先找到最大的数，把它翻转到第一个，接着翻转整个数列把它置于最后一个，这样完成一次操作
　　最大的数已经置于末尾，那么之后的操作需要对它不造成影响，所以把数列数 -1，也就是丢下最后一个数不管了
　　然后我们处理剩下的 n-1 个数列，即处理子问题
　　这里容易出现一个错误，如果最大的数为第一个数，那么就不需要进行第一次翻转，此处需要特判一下
    此处用的find()不属于vector，返回的是个迭代器
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void flip(vector<int> &data, int k) {
    cout << k << " ";
    int len = data.size();
    int begin = 0;
    int end = len - k; 
    while (begin < end) {
        data[begin] ^= data[end];
        data[end] ^= data[begin];
        data[begin] ^= data[end];
        begin++;
        end--;
    }
    return ;
}
void deal(vector<int> &data) {
    int len = data.size();
    vector<int> target(data);
    sort(target.begin(), target.end());
    int p = len - 1;
    // 从大到小依次归位
    while (p > 0) {
        int i = find(data.begin(), data.end(), target[p]) - data.begin();
        if (i == p) {                       // 已归位的情况
            p--;
            continue;
        }
        if (i > 0) {                        // 不在最上面（在最上面则只需要翻下面那次就可以了）
            flip(data, len - i);            
        }
        flip(data, len - p);
        p--;
    }
    cout << 0 << endl;
}
int main(){
    string s;
    stringstream ss;
    while (getline(cin, s)) {
        // 每次处理一个煎饼栈
        cout << s << endl;
        ss.clear();
        ss << s;
        string temp;
        vector<int> data;
        while (getline(ss, temp, ' ')) {
            data.push_back(temp[0] - '0');            
        }
        deal(data);
        //cout << s << endl;
    }

    return 0;
}
