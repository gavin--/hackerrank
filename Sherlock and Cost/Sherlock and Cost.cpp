#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        int B[N];
        for(auto i = 0; i != N; i++) {
            cin >> B[i];
        }
        long long dp[N][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(auto i = 1; i != N; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + B[i - 1] - 1);
            dp[i][1] = max(dp[i - 1][0] + B[i] - 1, dp[i - 1][1] + abs(B[i] - B[i - 1]));
        }
        cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
    }
    return 0;
}
