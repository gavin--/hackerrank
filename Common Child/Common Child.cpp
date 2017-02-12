#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    short dp[2][B.size() + 1], cur = 0, prev = 1;
    fill(dp[0], dp[0] + B.size() + 1, 0);
    for(auto i = 1; i <= A.size(); i++) {
        swap(cur, prev);
        dp[cur][0] = 0;
        for(auto j = 1; j <= B.size(); j++) {
            if(A[i - 1] == B[j - 1]) {
                dp[cur][j] = dp[prev][j - 1] + 1;
            } else {
                dp[cur][j] = max(dp[cur][j - 1], dp[prev][j]);
            }
        }
    }
    cout << dp[cur][B.size()];
    return 0;
}
