#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int m, r, s;
    cin >> m >> r >> s;
    int X[m], result = 0;
    for(auto i = 0; cin >> X[i]; i++) {
    }
    int n = (r + s) / 2, l = (r - s) / 2, dp[2][n + 1][m + 1];
    auto cur = 0, pre = 1;
    for(auto j = 0; j <= n; j++) {
        for(auto k = 0; k <= m; k++) {
            dp[cur][j][k] = 0;
        }
    }
    dp[cur][0][0] = 1;
    if(X[0] <= n) {
        dp[cur][X[0]][1] = 1;
    }
    for(auto i = 1; i < m; i++) {
        swap(cur, pre);
        dp[cur][0][0] = 1;
        for(auto k = 1; k <= m; k++) {
            dp[cur][0][k] = 0;
        }
        for(auto j = 1; j <= n; j++) {
            dp[cur][j][0] = 0;
            for(auto k = 1; k <= m; k++) {
                if(j < X[i]) {
                    dp[cur][j][k] = dp[pre][j][k];
                } else {
                    dp[cur][j][k] = (dp[pre][j - X[i]][k - 1] + dp[pre][j][k]) % MOD;
                }
            }
        }
    }
    if(l < 0 || (r + s) % 2 == 1 || (r - s) % 2 == 1 || r == 0) {
        cout << 0;
        return 0;
    }
    for(auto i = 0; i <= m; i++) {
        result = (result + (long long)dp[cur][n][i] * dp[cur][l][i]) % MOD;
    }
    cout << result;
    return 0;
}
