#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int n;
        cin >> n;
        vector<bool> dp(max(n, 5));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 1;
        for(auto i = 5; i < n; i++) {
            dp[i] = !(dp[i - 2] && dp[i - 3] && dp[i - 5]);
        }
        if(dp[n - 1]) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}
