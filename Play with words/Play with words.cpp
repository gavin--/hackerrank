#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    short dp[s.size()][s.size()];
    for(auto i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }
    for(auto i = 2; i <= s.size(); i++) {
        for(auto j = 0; j <= s.size() - i; j++) {
            auto k = j + i - 1;
            if(s[k] == s[j]) {
                if(i == 2) {
                    dp[j][k] = 2;
                } else {
                    dp[j][k] = dp[j + 1][k - 1] + 2;
                }
            } else {
                dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
            }
        }
    }
    auto result = 0;
    for(auto i = 0; i < s.size() - 1; i++) {
        result = max(result, (int)dp[0][i] * dp[i + 1][s.size() - 1]);
    }
    cout << result;
    return 0;
}
