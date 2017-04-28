#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, int n) {
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
    int T;
    for(cin >> T; T > 0; T--) {
        long long N, M;
        cin >> N >> M;
        if(M == 1 && N > 1 || M == 2 && N > 2) {
            cout << 0 << endl;
            continue;
        }
        auto result = M;
        if(N > 1) {
            result = result * (M - 1) % MOD;
        }
        if(N - 2 >= 0 && M - 2 > 0) {
            result = result * pow(M - 2, N - 2) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
