#include <iostream>
#include <algorithm>
using namespace std;

int pow(int X, int N) {
    auto result = 1ll;
    while(N != 0) {
        if(N % 2 == 1) {
            result *= X;
        }
        N /= 2;
        X *= X;
    }
    return result;
}

int main() {
    int X, N;
    cin >> X >> N;
    int dp[X + 1][X + 1];
    fill(dp[0], dp[0] + X + 1, 1);
    for(auto i = 1; i <= X; i++) {
        dp[i][0] = 0;
        auto j = 1;
        while(true) {
            dp[i][j] = dp[i][j - 1];
            auto k = pow(j, N);
            if(k > i) {
                break;
            }
            dp[i][j] += dp[i - k][j - 1];
            j++;
        }
        for(; j <= X; j++) {
            dp[i][j] = dp[i][j - 1];
        }
    }
    cout << dp[X][X];
    return 0;
}
