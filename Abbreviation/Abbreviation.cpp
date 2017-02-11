#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    for(cin >> q; q > 0; q--) {
        string a, b;
        cin >> a >> b;
        vector<bool> dp[a.size() + 1];
        fill(dp, dp + a.size() + 1, vector<bool>(b.size() + 1));
        dp[0][0] = 1;
        for(auto i = 1; i <= a.size(); i++) {
            dp[i][0] = islower(a[i - 1]);
        }
        for(auto i = 1; i <= b.size(); i++) {
            for(auto j = i; j <= a.size(); j++) {
                if(islower(a[j - 1])) {
                    dp[j][i] = dp[j - 1][i];
                    if(toupper(a[j - 1]) == b[i - 1] || a[j - 1] == b[i - 1]) {
                        dp[j][i] = dp[j][i] || dp[j - 1][i - 1];
                    }
                } else if(b[i - 1] == a[j - 1]) {
                    dp[j][i] = dp[j - 1][i - 1];
                } else {
                    dp[j][i] = 0;
                }
            }
        }
        if(dp[a.size()][b.size()]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
