#include <vector>
#include <iostream>
using namespace std;

int main() {
    int m, n, result = 0;
    cin >> m >> n;
    vector<bool> graph[m];
    for(auto i = 0; i != m; i++) {
        string s;
        cin >> s;
        graph[i].resize(n);
        for(auto j = 0; j != n; j++) {
            graph[i][j] = s[j] == 'x';
        }
    }
    int dp[m][m];
    for(int i = 0; i != m; i++) {
        for(int j = i + 1; j != m; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i = 0; i != n; i++) {
        for(int j = 0; j != m; j++) {
            bool marsh = false;
            for(int k = j + 1; k < m; k++) {
                if(graph[k][i] == 1) {
                    marsh = true;
                }
                if(graph[j][i] == 0 && graph[k][i] == 0) {
                    if(dp[j][k] >= 0) {
                        dp[j][k]++;
                    }
                    if(marsh == false) {
                        if(dp[j][k] < 0) {
                            dp[j][k] = 0;
                        } else if(dp[j][k] > 0) {
                            result = max(result, 2 * (dp[j][k] + k - j));
                        }
                    }
                } else {
                    dp[j][k] = -1;
                }
            }
        }
    }
    if(result == 0) {
        cout << "impossible";
    } else {
        cout << result;
    }
    return 0;
}
