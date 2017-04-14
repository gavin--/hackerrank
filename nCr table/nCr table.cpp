#include <iostream>
using namespace std;

const int MOD = 1000000000;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int dp[2][n + 1], cur = 0, prev = 1;
        for(auto i = 1; i <= n; i++) {
            swap(cur, prev);
            dp[cur][0] = 1;
            dp[cur][i] = 1;
            for(auto j = 1; j < i; j++) {
                dp[cur][j] = (dp[prev][j - 1] + dp[prev][j]) % MOD;
            }
        }
        for(auto i = 0; i <= n; i++) {
            cout << dp[cur][i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
