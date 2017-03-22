#include <iostream>
#include <algorithm>
using namespace std;

const string wrong = "WRONG PASSWORD\n";

string check(string* pass, string* dp, string& loginAttempt, int begin, int N) {
    if(begin == loginAttempt.size()) {
        return "\n";
    }
    if(!dp[begin].empty()) {
        return dp[begin];
    }
    for(auto i = 0; i != N; i++) {
        if(loginAttempt.compare(begin, pass[i].size(), pass[i]) == 0) {
            auto rest = check(pass, dp, loginAttempt, begin + pass[i].size(), N);
            if(rest != wrong) {
                auto result = pass[i] + " " + rest;
                dp[begin] = result;
                return result;
            }
        }
    }
    dp[begin] = wrong;
    return wrong;
}

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
        string dp[loginAttempt.size()];
        fill(dp, dp + loginAttempt.size(), "");
        cout << check(pass, dp, loginAttempt, 0, N);
    }
    return 0;
}
