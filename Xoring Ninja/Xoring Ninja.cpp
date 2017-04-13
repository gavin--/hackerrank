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
    int T;
    cin >> T;
    for(long long n; cin >> n; ) {
        long long result = 0;
        for(auto i = 0; i != n; i++) {
            long long a;
            cin >> a;
            result = result | a;
        }
        cout << result * pow(2, n - 1) % MOD << endl;
    }
    return 0;
}
