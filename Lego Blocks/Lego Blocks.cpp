#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long pow(long long n, int x) {
    auto result = 1;
    while(x > 0) {
        if(x % 2 == 1) {
            result = (result * n) % MOD;
        }
        n = (n * n) % MOD;
        x /= 2;
    }
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, M;
        cin >> N >> M;
        unsigned int dp1[max(M, 4)];
        dp1[0] = 1;
        dp1[1] = 2;
        dp1[2] = 4;
        dp1[3] = 8;
        for(auto i = 4; i < M; i++) {
            dp1[i] = (dp1[i - 1] + dp1[i - 2] + dp1[i - 3] + dp1[i - 4]) % MOD;
        }
        int dp2[M];
        dp2[0] = 1;
        for(auto i = 1; i != M; i++) {
            dp2[i] = pow(dp1[i], N);
            for(auto j = 0; j != i; j++) {
                dp2[i] = (((dp2[i] - pow(dp1[j], N) * dp2[i - j - 1]) % MOD) + MOD) % MOD;
            }
        }
        cout << dp2[M - 1] << endl;
    }
    return 0;
}
