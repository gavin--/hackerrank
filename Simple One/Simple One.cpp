#include <array>
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

array<long long, 2> solve(array<long long, 2>& tan, long long n) {
    if(n == 1) {
        return tan;
    }
    if(n % 2 == 1) {
        auto result = solve(tan, n - 1);
        return {(tan[0] * result[1] + result[0] * tan[1]) % MOD, (tan[1] * result[1] - tan[0] * result[0]) % MOD};
    }
    auto result = solve(tan, n / 2);
    return {2 * result[0] * result[1] % MOD, (result[1] * result[1] - result[0] * result[0]) % MOD};
}

int main() {
    int T;
    cin >> T;
    for(array<long long, 2> tan; cin >> tan[0] >> tan[1]; ) {
        long long n;
        cin >> n;
        auto result = solve(tan, n);
        cout << (result[0] * inverse(result[1]) % MOD + MOD) % MOD << endl;
    }
    return 0;
}
