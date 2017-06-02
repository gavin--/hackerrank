#include <iostream>
#include <climits>
using namespace std;

int main() {
    int Q, max = 0;
    cin >> Q;
    int queries[Q];
    for(auto i = 0; cin >> queries[i]; i++) {
        if(queries[i] > max) {
            max = queries[i];
        }
    }
    short dp[max + 1];
    dp[0] = 0;
    fill(dp + 1, dp + max + 1, SHRT_MAX);
    for(auto i = 1; i <= max; i++) {
        if(dp[i - 1] < dp[i]) {
            dp[i] = dp[i - 1] + 1;
        }
        for(auto j = 2; j <= i && i * j <= max; j++) {
            if(dp[i] < dp[i * j]) {
                dp[i * j] = dp[i] + 1;
            }
        }
    }
    for(auto i = 0; i != Q; i++) {
        cout << dp[queries[i]] << endl;
    }
    return 0;
}
