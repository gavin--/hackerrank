#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(long long n, m; cin >> n >> m; ) {
        long long S[m + 1], dp[m + 1], result = 0;
        for(auto i = 1; i <= m; i++) {
            cin >> S[i];
        }
        S[0] = n;
        sort(S + 1, S + m + 1, greater<long long>());
        for(auto i = 0; i <= m; i++) {
            dp[i] = 0;
            for(auto j = 0; j < i; j++) {
                if(S[j] % S[i] == 0 && S[i] != S[j] && dp[j] + n / S[j] > dp[i]) {
                    if(j == 0 || dp[j] != 0) {
                        dp[i] = dp[j] + n / S[j];
                        result = max(result, dp[i]);
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
