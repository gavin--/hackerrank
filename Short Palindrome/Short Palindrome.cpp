#include <iostream>
#include <set>
using namespace std;

const long long MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    set<char> set(s.begin(), s.end());
    auto result = 0ll;
    for(auto i : set) {
        for(auto j : set) {
            auto p = string(1, i) + string(2, j) + string(1, i);
            long long dp[p.size() + 1] = {1, 0, 0, 0, 0};
            for(auto i = 1; i <= s.size(); i++) {
                dp[0] = 1;
                for(auto j = 4; j >= 0; j--) {
                    if(s[i - 1] == p[j - 1]) {
                        dp[j] = (dp[j] + dp[j - 1]) % MOD;
                    }
                }
            }
            result = (result + dp[p.size()]) % MOD;
        }
    }
    cout << result;
    return 0;
}
