#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
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
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        if(gcd(a, b) == gcd(x, y)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
