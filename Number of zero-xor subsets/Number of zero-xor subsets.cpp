#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long exp(long long x, long long n, long long mod) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % mod;
        }
        x = x * x % mod;
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long N;
        cin >> N;
        cout << exp(2, ((exp(2, N, MOD - 1) - N) % (MOD - 1) + MOD - 1) % (MOD - 1), MOD) << endl;
    }
    return 0;
}
