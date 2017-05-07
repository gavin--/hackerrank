#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    pair<int, int> edge[n - 1];
    int dp[n][n], result = n;
    for(auto i = 0; i < n; i++) {
        for(auto j = 0; j < n; j++) {
            dp[i][j] = n;
        }
        dp[i][i] = 0;
    }
    for(auto i = 0; cin >> edge[i].first >> edge[i].second; i++) {
        edge[i].first--;
        edge[i].second--;
        dp[edge[i].first][edge[i].second] = 1;
        dp[edge[i].second][edge[i].first] = 1;
    }
    for(auto i = 0; i < n; i++) {
        for(auto j = 0; j < n; j++) {
            for(auto k = 0; k < n; k++) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    if(k % 2 == 0) {
        for(auto i = 0; i < n; i++) {
            auto unmarked = 0;
            for(auto j = 0; j < n; j++) {
                if(dp[i][j] <= k / 2) {
                    unmarked++;
                }
            }
            result = min(result, n - unmarked);
        }
    } else {
        for(auto i = 0; i < n - 1; i++) {
            auto unmarked = 0;
            for(auto j = 0; j < n; j++) {
                if(dp[edge[i].first][j] <= k / 2 || dp[edge[i].second][j] <= k / 2) {
                    unmarked++;
                }
            }
            result = min(result, n - unmarked);
        }
    }
    cout << result;
    return 0;
}
