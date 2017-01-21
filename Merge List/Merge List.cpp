#include <iostream>
using namespace std;

const int MOD = 1000000007;

int exp(int x, int n) {
    auto result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = (long long)result * x % MOD;
        }
        n /= 2;
        x = (long long)x * x % MOD;
    }
    return result;
}

int inverse(int n) {
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
