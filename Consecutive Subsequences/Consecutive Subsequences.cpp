#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int n, k, a;
        cin >> n >> k;
        int dp[2][k];
        fill(dp[0], dp[0] + k, 0);
        cin >> a;
        dp[0][a % k]++;
        long long result = dp[0][0];
        for(auto i = 1, cur = 0, prev = 1; i != n; i++) {
            int a;
            cin >> a;
            swap(cur, prev);
            for(auto j = 0; j != k; j++) {
                dp[cur][j] = dp[prev][(j - a % k + k) % k];
            }
            dp[cur][a % k]++;
            result += dp[cur][0];
        }
        cout << result << endl;
    }
    return 0;
}
