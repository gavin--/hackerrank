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
    for(int N; cin >> N; ) {
        int d = 0;
        for(auto i = 0; i != N; i++) {
            int A;
            cin >> A;
            d = gcd(A, d);
        }
        if(d > 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
