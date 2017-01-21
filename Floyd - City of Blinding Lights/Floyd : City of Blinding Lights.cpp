#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int dp[N][N];
    const int MAX = N * 350;
    for(auto i = 0; i != N; i++) {
        for(auto j = 0; j != N; j++) {
            dp[i][j] = MAX;
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
                if(dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    int Q;
    for(cin >> Q; Q > 0; Q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(dp[a][b] == MAX) {
            cout << -1;
        } else {
            cout << dp[a][b];
        }
        cout << endl;
    }
    return 0;
}
