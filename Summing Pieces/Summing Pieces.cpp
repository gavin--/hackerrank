#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    long long sum[n + 1], pow[n + 1], dp = 0;
    pow[0] = 1;
    sum[0] = 0;
    for(auto i = 0; cin >> sum[i + 1]; i++) {
        sum[i + 1] = (sum[i] + sum[i + 1]) % MOD;
    }
    for(auto i = 1, j = 0; i <= n; i++) {
        pow[i] = pow[i - 1] * 2 % MOD;
        j = (pow[max(i - 2, 0)] * sum[i - 1] + j) % MOD;
        dp = (2 * dp + pow[i - 1] * sum[i] + (pow[i - 1] - 1ll) * (sum[i] - sum[i - 1]) - j) % MOD;
        dp = (dp + MOD) % MOD;
    }
    cout << dp;
    return 0;
}
