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
        int N;
        cin >> N;
        int A[N];
        for(auto i = 0; i != N; i++) {
            cin >> A[i];
        }
        auto d = A[0];
        for(auto i = 1; i < N; i++) {
            d = gcd(A[i], d);
        }
        if(d > 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
