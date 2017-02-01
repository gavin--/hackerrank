#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long exp(long long x, int n) {
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
    return exp(n, MOD - 2);
}

long long C(long long n, long long k) {
	auto result = 1ll, temp = 1ll;
	for(auto i = 1; i <= k; i++) {
		result = result * (n - i + 1) % MOD;
		temp = temp * i % MOD;
	}
	return result * inverse(temp) % MOD;
}

int main() {
    int A, B;
    cin >> A >> B;
    if(A < 24 && B != 25 || A != 25 && B < 24 || A >= 24 && B >= 24 && abs(A - B) != 2) {
        cout << 0;
    } else if(A < 25 || B < 25) {
        A = min(A, 24);
        B = min(B, 24);
        cout << C(A + B, B);
    } else {
        cout << (C(48, 24) * exp(2, min(A, B) - 24)) % MOD;
    }
    return 0;
}
