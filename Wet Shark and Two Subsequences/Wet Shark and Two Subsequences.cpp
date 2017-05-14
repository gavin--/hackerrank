#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int m, r, s;
    cin >> m >> r >> s;
    int X[m], result = 0;
    for(auto i = 0; cin >> X[i]; i++) {
    }
    int n = (r + s) / 2, l = (r - s) / 2, dp[n + 1][m + 1];
    for(auto j = 0; j <= n; j++) {
        for(auto k = 0; k <= m; k++) {
            dp[j][k] = 0;
        }
    }
    dp[0][0] = 1;
    if(X[0] <= n) {
        dp[X[0]][1] = 1;
    }
    for(auto i = 1; i < m; i++) {
        dp[0][0] = 1;
        for(auto k = 1; k <= m; k++) {
            dp[0][k] = 0;
        }
        for(auto j = n; j >= 1; j--) {
            dp[j][0] = 0;
            for(auto k = 1; k <= m; k++) {
                if(j < X[i]) {
                    dp[j][k] = dp[j][k];
                } else {
                    dp[j][k] = (dp[j - X[i]][k - 1] + dp[j][k]) % MOD;
                }
            }
        }
    }
    if(l >= 0 && (r + s) % 2 != 1 && (r - s) % 2 != 1 && r != 0) {
        for(auto i = 0; i <= m; i++) {
            result = (result + (long long)dp[n][i] * dp[l][i]) % MOD;
        }
    }
    cout << result;
    return 0;
}
