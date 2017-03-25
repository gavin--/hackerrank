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
    for(cin >> T; T > 0; T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(max(a, b) >= c && c % gcd(a, b) == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
