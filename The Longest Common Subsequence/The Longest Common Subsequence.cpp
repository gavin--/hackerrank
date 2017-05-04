#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int A[n], B[m], dp[n + 1][m + 1];
    for(auto i = 0; i != n; i++) {
        cin >> A[i];
    }
    for(auto i = 0; cin >> B[i]; i++) {
    }
    fill(dp[0], dp[0] + m + 1, 0);
    for(auto i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for(auto j = 1; j <= m; j++) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    int lcs[dp[n][m]];
    for(auto i = n, j = m, k = dp[n][m] - 1; dp[i][j] != 0; ) {
        if(dp[i - 1][j] == dp[i][j]) {
            i--;
        } else if(dp[i][j - 1] == dp[i][j]) {
            j--;
        } else {
            i--;
            j--;
            lcs[k] = A[i];
            k--;
        }
    }
    for(auto i = 0; i < dp[n][m] - 1; i++) {
        cout << lcs[i] << ' ';
    }
    cout << lcs[dp[n][m] - 1];
    return 0;
}
