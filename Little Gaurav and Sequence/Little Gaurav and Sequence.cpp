#include <iostream>
using namespace std;

const long long MOD = 10;

long long pow(long long x, long long n, long long mod) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % mod;
        }
        n /= 2;
        x = x * x % mod;
    }
    return result;
}

long long pow(long long x, long long n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x;
        }
        n /= 2;
        x = x * x;
    }
    return result;
}

int main() {
    int T, result = 0;
    for(cin >> T; T > 0; T--) {
        long long N, result = 0;
        cin >> N;
        for(auto i = 0ll; ; i++) {
            auto t = pow(2, i);
            if(t > N) {
                break;
            }
            result = (result + pow(2, t, MOD)) % MOD;
        }
        result = result * (pow(4, N + 1, MOD) + 9) * 7 % MOD;
        cout << result << endl;
    }
    return 0;
}
