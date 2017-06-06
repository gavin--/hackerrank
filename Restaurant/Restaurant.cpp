#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    for(int l, b; cin >> l >> b; ) {
        auto d = gcd(l, b);
        cout << (l / d) * (b / d) << endl;
    }
    return 0;
}
