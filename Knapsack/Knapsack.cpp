#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(auto i = 0; i != n; i++) {
            cin >> a[i];
        }
        int dp[k + 1];
        dp[0] = 0;
        for(auto i = 1; i <= k; i++) {
            dp[i] = 0;
            for(auto& j : a) {
                if(j <= i) {
                    dp[i] = max(dp[i], j + dp[i - j]);
                }
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
