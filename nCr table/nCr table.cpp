#include <iostream>
using namespace std;

const int MOD = 1000000000;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int dp[n + 1];
        for(auto i = 1; i <= n; i++) {
            dp[0] = 1;
            dp[i] = 1;
            for(auto j = i - 1; j > 0; j--) {
                dp[j] = (dp[j - 1] + dp[j]) % MOD;
            }
        }
        for(auto i = 0; i <= n; i++) {
            cout << dp[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
