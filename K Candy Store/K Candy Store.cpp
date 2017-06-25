#include <iostream>
using namespace std;

const int MOD = 1000000000;

int main() {
    int T;
    cin >> T;
    for(int N, K; cin >> N >> K; ) {
        int dp[N + K];
        for(auto i = 1; i < N + K; i++) {
            dp[0] = 1;
            dp[i] = 1;
            for(auto j = i - 1; j > 0; j--) {
                dp[j] = (dp[j - 1] + dp[j]) % MOD;
            }
        }
        cout << dp[N - 1] << endl;
    }
    return 0;
}
