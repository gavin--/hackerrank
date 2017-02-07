#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long exp(long long x, int n) {
    auto result = 1ll;
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

int C(int n, int k) {
    auto result = 1ll, temp = 1ll;
    for(auto i = 1; i <= k; i++) {
        result = result * (n - i + 1) % MOD;
        temp = temp * i % MOD;
    }
    return result * inverse(temp) % MOD;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, M;
        cin >> N >> M;
        cout << C(N + M, N) << endl;
    }
    return 0;
}
