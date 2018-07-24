#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long n, m, q; cin >> n >> m >> q; ) {
        long long dp[n], last = (n - 1) / 2 + 1, change[last + 1];
        dp[1] = 1;
        for(long long i = n; i > 1; i--) {
            dp[1] = dp[1] * i % m;
        }
        if(n % 2 == 0) {
            change[last] = last + 1;
        } else {
            change[last] = 1;
        }
        for(long long i = last - 1; i >= 1; i--) {
            change[i] = change[i + 1] * (i + 1) % m * (n - i + 1) % m;
        }
        for(long long i = 2; i <= n / 2; i++) {
            dp[i] = dp[i - 1] * change[i] % m;
        }
        for(long long i = n - 1; i > n / 2; i--) {
            dp[i] = dp[n - i];
        }
        for(int r; q > 0; q--) {
            cin >> r;
            cout << dp[r] << endl;
        }
    }
    return 0;
}
