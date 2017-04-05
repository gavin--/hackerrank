#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, G, sum = 0;
        cin >> N >> G;
        int A[N];
        for(auto i = 0; i != N; i++) {
            cin >> A[i];
            sum += A[i];
        }
        G = min(G, sum);
        vector<bool> dp[G + 1];
        dp[0] = vector<bool>(2, 1);
        for(auto i = 1; i <= G; i++) {
            dp[i] = vector<bool>(2, 0);
        }
        auto cur = 0, prev = 1;
        for(auto i = 1; i <= N; i++) {
            swap(cur, prev);
            for(auto j = 0; j <= G; j++) {
                dp[j][cur] = dp[j][prev];
                if(j >= A[i - 1]) {
                    dp[j][cur] = dp[j][cur] || dp[j - A[i - 1]][prev];
                }
            }
        }
        auto result = false;
        for(auto i = 0; i <= G; i++) {
            if(dp[i][cur] && sum - i <= G) {
                result = true;
            }
        }
        if(result) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
