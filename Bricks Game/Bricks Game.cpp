#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        int b[N];
        for(auto i = 0; i != N; i++) {
            cin >> b[i];
        }
        long long dp[N + 1];
        dp[N] = 0;
        auto sum = 0ll;
        for(auto i = N - 1; i >= 0; i--) {
            dp[i] = b[i] + sum - dp[i + 1];
            if(i + 1 < N) {
                dp[i] = max(dp[i], b[i] + sum - dp[i + 2]);
            }
            if(i + 2 < N) {
                dp[i] = max(dp[i], b[i] + sum - dp[i + 3]);
            }
            sum += b[i];
        }
        cout << dp[0] << endl;
    }
    return 0;
}
