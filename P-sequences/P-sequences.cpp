#include <vector>
#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int isqrt(int n) {
    auto begin = 1, end = n / 2 + 1;
    while(begin < end) {
        auto mid = (end + begin + 1) / 2;
        if(mid <= n / mid) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

int main() {
    int N, P;
    cin >> N >> P;
    vector<long long> dp[2];
    dp[0] = vector<long long>(2 * isqrt(P), 1);
    auto cur = 0, prev = 1;
    for(auto i = 1; i <= N; i++) {
        swap(cur, prev);
        dp[cur].emplace_back(dp[prev].back());
        for(int j = P / 2, k = dp[prev].size() - 2; j > 0; j = P / (P / j + 1), k--) {
            dp[cur].emplace_back((dp[cur].back() + dp[prev][k] * (P / j - P / (j + 1))) % MOD);
        }
        dp[prev].clear();
    }
    cout << dp[cur].back();
    return 0;
}
