#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    auto result = 1ll, A = 1ll, B = 1ll;
    auto same = true;
    for(auto i = 0; i != N; i++) {
        long long p, b, a;
        cin >> p >> b >> a;
        auto n = pow(p, a), m = pow(p, b);
        if(a != b) {
            result = (result * n + result * m) % MOD;
            same = false;
        } else {
            result = result * n % MOD;
        }
        A = A * n % MOD;
        B = B * m % MOD;
    }
    if(same) {
        result = (A + B) % MOD;
    }
    cout << result;
    return 0;
}
