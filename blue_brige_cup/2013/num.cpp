#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int num = lcm(a, b);
    num = lcm(num, c);
    cout << num << endl;
    return 0;
}
