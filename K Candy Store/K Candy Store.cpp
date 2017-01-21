#include <iostream>
using namespace std;

const int MOD = 1000000000;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, K;
        cin >> N >> K;
        int dp[N + K][N + K];
        for(auto i = 1; i < N + K; i++) {
            dp[i][0] = 1;
            dp[i][i] = 1;
            for(auto j = 1; j < i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
        cout << dp[N + K - 1][N - 1] << endl;
    }
    return 0;
}
