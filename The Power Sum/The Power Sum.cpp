#include <iostream>
#include <algorithm>
using namespace std;

int pow(int X, int N) {
    auto result = 1;
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
        for(auto j = 0; j <= X; j++) {
            dp[i][j] = 0;
            for(auto k = 0; k < j; k++) {
                auto l = pow(k, N);
                if(l > i) {
                    break;
                }
                dp[i][j] += dp[i - l][k];
            }
        }
    }
    cout << dp[X][X];
    return 0;
}
