#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int*** dp;

int solve(int n, int m, int k, string* map) {
    if(dp[n][m][k] != -2) {
        return dp[n][m][k];
    }
    if(map[n][m] == '*') {
        return 0;
    }
    if(k == 0) {
        return -1;
    }
    auto result = -1;
    if(n > 0) {
        auto t = solve(n - 1, m, k - 1, map);
        if(t != -1) {
            if(map[n][m] != 'U') {
                t++;
            }
            if(result == -1) {
                result = t;
            } else {
                result = min(result, t);
            }
        }
    }
    if(m > 0) {
        auto t = solve(n, m - 1, k - 1, map);
        if(t != -1) {
            if(map[n][m] != 'L') {
                t++;
            }
            if(result == -1) {
                result = t;
            } else {
                result = min(result, t);
            }
        }
    }
    if(n + 1 < N) {
        auto t = solve(n + 1, m, k - 1, map);
        if(t != -1) {
            if(map[n][m] != 'D') {
                t++;
            }
            if(result == -1) {
                result = t;
            } else {
                result = min(result, t);
            }
        }
    }
    if(m + 1 < M) {
        auto t = solve(n, m + 1, k - 1, map);
        if(t != -1) {
            if(map[n][m] != 'R') {
                t++;
            }
            if(result == -1) {
                result = t;
            } else {
                result = min(result, t);
            }
        }
    }
    dp[n][m][k] = result;
    return result;
}

int main() {
    cin >> N >> M >> K;
    string map[N];
    dp = new int**[N];
    for(auto i = 0; i < N; i++) {
        dp[i] = new int*[M];
        for(auto j = 0; j < M; j++) {
            dp[i][j] = new int[K + 1];
            fill(dp[i][j], dp[i][j] + K + 1, -2);
        }
    }
    for(auto i = 0; cin >> map[i]; i++) {
    }
    cout << solve(0, 0, K, map);
    return 0;
}
