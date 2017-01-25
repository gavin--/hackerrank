#include <iostream>
using namespace std;

long long pow(long long a, long long n, long long x) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * a % x;
        }
        a = a * a % x;
        n /= 2;
    }
    return result;
}

long long inverse(long long a, long long b) {
    pair<long long, long long> s = {1, 0}, r = {a, b};
    while(r.second != 0) {
        auto q = r.first / r.second;
        r = {r.second, r.first - q * r.second};
        s = {s.second, s.first - q * s.second};
    }
    return s.first;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long A, B, X;
        cin >> A >> B >> X;
        if(B < 0) {
            B = -B;
            A = (inverse(A, X) + X) % X;
        }
        cout << pow(A, B, X) << endl;
    }
    return 0;
}
