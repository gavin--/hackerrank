#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M;
    int dp[N][N];
    for(auto i = 0; i != N; i++) {
        for(auto j = 0; j != N; j++) {
            dp[i][j] = INT_MAX;
        }
        dp[i][i] = 0;
    }
    for(auto i = 0; i != M; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        dp[x - 1][y - 1] = r;
    }
    for(auto k = 0; k != N; k++) {
        for(auto i = 0; i != N; i++) {
            for(auto j = 0; j != N; j++) {
                if(dp[i][k] < dp[i][j] - dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    cin >> Q;
    for(int a, b; cin >> a >> b; cout << endl) {
        a--;
        b--;
        if(dp[a][b] == INT_MAX) {
            cout << -1;
        } else {
            cout << dp[a][b];
        }
    }
    return 0;
}
