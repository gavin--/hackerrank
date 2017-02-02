#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        long long dp[N + 1];
        dp[0] = 1;
        for(auto i = 1; i <= N; i++) {
            if(i <= 3) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + dp[i - 4];
            }
        }
        vector<bool> prime(dp[N] + 1, 1);
        for(auto i = 2; i * i <= dp[N]; i++) {
            if(prime[i]) {
                for(auto j = i * i; j <= dp[N]; j += i) {
                    prime[j] = 0;
                }
            }
        }
        auto result = 0ll;
        for(auto i = 2; i <= dp[N]; i++) {
            if(prime[i]) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
