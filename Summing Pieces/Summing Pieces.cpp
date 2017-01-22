#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    long long a[n], sum[n + 1], pow[n + 1], dp[n + 1];
    pow[0] = 1;
    sum[0] = 0;
    for(auto i = 0; cin >> a[i]; i++) {
        sum[i + 1] = (sum[i] + a[i]) % MOD;
    }
    dp[0] = 0;
    for(auto i = 1, j = 0; i <= n; i++) {
        pow[i] = pow[i - 1] * 2 % MOD;
        j = (pow[max(i - 2, 0)] * sum[i - 1] + j) % MOD;
        dp[i] = (2 * dp[i - 1] + pow[i - 1] * sum[i] + (pow[i - 1] - 1ll) * a[i - 1] - j) % MOD;
        dp[i] = (dp[i] + MOD) % MOD;
    }
    cout << dp[n];
    return 0;
}
