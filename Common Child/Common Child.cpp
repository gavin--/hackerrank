#include <iostream>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    short** dp = new short*[A.size() + 1];
    for(auto i = 0; i <= A.size(); i++) {
        dp[i] = new short[B.size() + 1];
    }
    for(auto i = 0; i <= B.size(); i++) {
        dp[0][i] = 0;
    }
    for(auto i = 1; i <= A.size(); i++) {
        dp[i][0] = 0;
        for(auto j = 1; j <= B.size(); j++) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[A.size()][B.size()];
    return 0;
}
