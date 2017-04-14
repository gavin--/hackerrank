#include <iostream>
using namespace std;

const long long MOD = 1000000007, c48c24 = 603457371;

long long pow(long long x, int n) {
    auto result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

long long inverse(long long n) {
    return pow(n, MOD - 2);
}

long long C(long long n, long long k) {
    auto top = 1ll, bottom = 1ll;
    for(auto i = 1; i <= k; i++) {
        top = top * (n - i + 1) % MOD;
        bottom = bottom * i % MOD;
    }
    return top * inverse(bottom) % MOD;
}

int main() {
    int A, B;
    cin >> A >> B;
    if(A < 24 && B != 25 || A != 25 && B < 24 || A >= 24 && B >= 24 && abs(A - B) != 2) {
        cout << 0;
    } else if(A <= 25 || B <= 25) {
        A = min(A, 24);
        B = min(B, 24);
        cout << C(A + B, B);
    } else {
        cout << c48c24 * pow(2, min(A, B) - 24) % MOD;
    }
    return 0;
}
