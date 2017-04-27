#include <iostream>
using namespace std;

const long long MOD = 1000000007;
long long* factorial, *ifactorial;

long long C(long long n, long long m) {
    return factorial[n] * ifactorial[m] % MOD * ifactorial[n - m] % MOD;
}

void precompute(long long n, long long k) {
    factorial = new long long[n + k - 1];
    ifactorial = new long long[n + k - 1];
    long long inv[n + k - 1];
    inv[1] = 1;
    factorial[0] = 1;
    factorial[1] = 1;
    ifactorial[0] = 1;
    ifactorial[1] = 1;
    for(auto i = 2ll; i <= n + k - 2; i++) {
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        factorial[i] = factorial[i - 1] * i % MOD;
        ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
    }
}

int main() {
    int T;
    cin >> T;
    for(long long n, lo, hi; cin >> n >> lo >> hi; ) {
        auto k = hi - lo + 1, result = 0ll;
        if(k == 1) {
            result = 1;
        } else {
            precompute(n, k);
            for(auto i = (n + k - 2) / k + 1; i <= n; i++) {
                auto current = 0ll;
                for(auto j = 1, sign = 1; j <= min((n + k - 2) / i, n / i); j++, sign *= -1) {
                    current = (current + sign * C(n + k - 2 - j * i, k - 2) * C(k - 1, j - 1)) % MOD;
                }
                result = (result + k * current) % MOD;
            }
            delete[](factorial);
            delete[](ifactorial);
        }
        cout << result << endl;
    }
    return 0;
}
