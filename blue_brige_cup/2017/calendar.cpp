// 注意可能还原出相同的日期，要用set去重
// 并且要求按日期从早到晚排序，因此这里重载了日期类的运算符'<'

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
struct node {
    int y, m, d;
    node() {}
    node(int year, int month, int day) {
        y = year; m = month; d = day;
    }
    bool operator<(const node &obj) const {
        if (y == obj.y) {
            if (m == obj.m) {
                return d < obj.d;
            } else {
                return m < obj.m;
            }
        } else {
            return y < obj.y;
        }
    }
};
set<node> s;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
int isValid(int y, int m, int d) {
    if (y < 1960 || y > 2059) return 0;
    if (m < 1 || m > 12) return 0;
    if (d < 1 || d > month[m] + (m == 2 && leap(y))) return 0;
    return 1;
}
int main(){
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    int y, m, d;
    // 年/月/日
    y = 1900 + a; m = b; d = c;
    if (isValid(y, m, d)) s.insert(node(y, m, d));
    y = 2000 + a; m = b; d = c;
    if (isValid(y, m, d)) s.insert(node(y, m, d));
    // 月/日/年
    y = 1900 + c; m = a; d = b;
    if (isValid(y, m, d)) s.insert(node(y, m, d));
    y = 2000 + c; m = a; d = b;
    if (isValid(y, m, d)) s.insert(node(y, m, d));
    // 日/月/年
    y = 1900 + c; m = b; d = a;
    if (isValid(y, m, d)) s.insert(node(y, m, d));
    y = 2000 + c; m = b; d = a;
    if (isValid(y, m, d)) s.insert(node(y, m, d));
    for (set<node>::iterator it = s.begin(); it != s.end(); it++) {
        printf("%d-%02d-%02d\n", it->y, it->m, it->d);
    }
    return 0;
}
