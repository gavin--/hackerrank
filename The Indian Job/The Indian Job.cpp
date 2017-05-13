#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    for(int N, G; cin >> N >> G; ) {
        int A[N], sum = 0;
        for(auto i = 0; i != N; i++) {
            cin >> A[i];
            sum += A[i];
        }
        G = min(G, sum);
        vector<bool> dp(G + 1, 0);
        dp[0] = 1;
        for(auto i = 1; i <= N; i++) {
            for(auto j = G; j >= 0; j--) {
                if(j >= A[i - 1]) {
                    dp[j] = dp[j] || dp[j - A[i - 1]];
                }
            }
        }
        string result = "NO\n";
        for(auto i = 0; i <= G; i++) {
            if(dp[i] && sum - i <= G) {
                result = "YES\n";
            }
        }
        cout << result;
    }
    return 0;
}
