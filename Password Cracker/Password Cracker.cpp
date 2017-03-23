#include <iostream>
using namespace std;

const string wrong = "WRONG PASSWORD";

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        string pass[N], loginAttempt;
        for(auto i = 0; i != N; i++) {
            cin >> pass[i];
        }
        cin >> loginAttempt;
        string dp[loginAttempt.size() + 1];
        dp[0] = "";
        for(auto i = 1; i <= loginAttempt.size(); i++) {
            dp[i] = wrong;
            for(auto j = 0; j != N; j++) {
                if(i >= pass[j].size() && loginAttempt.compare(i - pass[j].size(), pass[j].size(), pass[j]) == 0 && dp[i - pass[j].size()] != wrong) {
                    dp[i] = dp[i - pass[j].size()] + " " + pass[j];
                    break;
                }
            }
        }
        cout << dp[loginAttempt.size()] << '\n';
    }
    return 0;
}
