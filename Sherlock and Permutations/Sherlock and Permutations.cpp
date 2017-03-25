#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
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

long long inverse(long long N) {
    return pow(N, MOD - 2);
}

long long C(long long N, long long M) {
    auto top = 1ll, bottom = 1ll;
    for(auto i = 1ll; i <= M; i++) {
        top = top * (N + 1 - i) % MOD;
        bottom = bottom * i % MOD;
    }
    return top * inverse(bottom) % MOD;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long N, M;
        cin >> N >> M;
        cout << C(N + M - 1, N) << endl;
    }
    return 0;
}
