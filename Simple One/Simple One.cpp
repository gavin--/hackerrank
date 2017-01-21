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

long long inverse(long long n) {
    return pow(n, MOD - 2);
}

pair<long long, long long> solve(pair<long long, long long>& tan, long long n) {
    if(n == 1) {
        return tan;
    }
    if(n % 2 == 1) {
        auto result = solve(tan, n - 1);
        result = {(tan.first * result.second + result.first * tan.second) % MOD, (tan.second * result.second - tan.first * result.first) % MOD};
        return result;
    }
    auto result = solve(tan, n / 2);
    result = {2 * result.first * result.second % MOD, (result.second * result.second - result.first * result.first) % MOD};
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        pair<long long, long long> tan;
        long long n;
        cin >> tan.first >> tan.second >> n;
        auto result = solve(tan, n);
        cout << (result.first * inverse(result.second) % MOD + MOD) % MOD << endl;
    }
    return 0;
}
