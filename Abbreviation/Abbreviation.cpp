#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(string a, b; cin >> a >> b; ) {
        bool dp[2][a.size() + 1], cur = 0, pre = 1;
        dp[0][0] = 1;
        for(auto i = 1; i <= a.size(); i++) {
            dp[0][i] = islower(a[i - 1]);
        }
        for(auto i = 1; i <= b.size(); i++) {
            swap(cur, pre);
            dp[cur][i - 1] = 0;
            for(auto j = i; j <= a.size(); j++) {
                if(islower(a[j - 1])) {
                    dp[cur][j] = dp[cur][j - 1];
                    if(toupper(a[j - 1]) == b[i - 1] || a[j - 1] == b[i - 1]) {
                        dp[cur][j] = dp[cur][j] || dp[pre][j - 1];
                    }
                } else if(b[i - 1] == a[j - 1]) {
                    dp[cur][j] = dp[pre][j - 1];
                } else {
                    dp[cur][j] = 0;
                }
            }
        }
        if(dp[cur][a.size()]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
