#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int dp[N + 1], c[N];
        dp[0] = 1;
        for(auto i = 0; i < N; i++) {
            cin >> c[i];
        }
        sort(c, c + N);
        for(auto i = 1; i <= N; i++) {
            long long t = i - c[i - 1];
            if(t < 0) {
                dp[N] = 0;
                break;
            }
            dp[i] = dp[i - 1] * t % MOD;
        }
        cout << dp[N] << endl;
    }
    return 0;
}
