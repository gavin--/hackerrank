#include <iostream>
#include <climits>
using namespace std;

int main() {
    int q, size = 0;
    cin >> q;
    int queries[q];
    for(int i = 0; cin >> queries[i]; i++) {
        size = max(size, queries[i]);
    }
    int dp[size + 1];
    dp[0] = 0;
    fill(dp + 1, dp + size + 1, INT_MAX);
    for(int i = 1; i <= size; i++) {
        if(dp[i - 1] < dp[i]) {
            dp[i] = dp[i - 1] + 1;
        }
        for(int j = 2; j <= i && i * j <= size; j++) {
            if(dp[i] < dp[i * j]) {
                dp[i * j] = dp[i] + 1;
            }
        }
    }
    for(int i = 0; i != q; i++) {
        cout << dp[queries[i]] << endl;
    }
    return 0;
}
