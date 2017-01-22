#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int C[M + 1];
    long long dp[N + 1][M + 1];
    for(auto i = 1; cin >> C[i]; i++) {
    }
    for(auto i = 0; i <= M; i++) {
        dp[0][i] = 1;
    }
    for(auto i = 1; i <= N; i++) {
        dp[i][0] = 0;
        for(auto j = 1; j <= M; j++) {
            dp[i][j] = dp[i][j - 1];
            if(C[j] <= i) {
                dp[i][j] += dp[i - C[j]][j];
            }
        }
    }
    cout << dp[N][M];
    return 0;
}
