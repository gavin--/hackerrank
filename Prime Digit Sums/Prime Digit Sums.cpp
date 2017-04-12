#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1000000007;
vector<bool> prime {
    false,
    false,
    true,
    true,
    false,
    true,
    false,
    true,
    false,
    false,
    false,
    true,
    false,
    true,
    false,
    false,
    false,
    true,
    false,
    true,
    false,
    false,
    false,
    true,
    false,
    false,
    false,
    false,
    false,
    true,
    false,
    true,
    false,
    false,
    false,
    false,
    false,
    true,
    false,
    false,
    false,
    false,
    false,
    true,
    false,
    false
};
int count[2][10001];

int main() {
    int q, maxn = 1, index = 0;
    cin >> q;
    vector<int> valid[2];
    for(short i = 1; i <= 9; i++) {
        for(short j = 0; j <= 9; j++) {
            for(short k = 0; k <= 9; k++) {
                for(short l = 0; l <= 9; l++) {
                    if(prime[i + j + k + l] && prime[i + j + k] && prime[j + k + l]) {
                        auto num = l + 10 * k + 100 * j + 1000 * i;
                        count[index][num]++;
                        valid[index].emplace_back(num);
                    }
                }
            }
        }
    }
    int queries[q];
    for(auto i = 0; cin >> queries[i]; i++) {
        maxn = max(maxn, queries[i]);
    }
    int dp[max(maxn + 1, 5)];
    dp[1] = 9;
    dp[2] = 90;
    dp[3] = 303;
    dp[4] = valid[index].size();
    for(auto i = 5; i <= maxn; i++) {
        dp[i] = 0;
        index = 1 - index;
        for(auto j = 0; j <= 9; j++) {
            for(auto& k : valid[1 - index]) {
                auto d1 = k % 10;
                auto d2 = (k / 10) % 10;
                auto d3 = (k / 100) % 10;
                auto d4 = (k / 1000) % 10;
                auto find5 = prime[d1 + d2 + d3 + d4 + j];
                auto find4 = prime[d1 + d2 + d3 + j];
                auto find3 = prime[d1 + d2 + j];
                if(find3 && find4 && find5) {
                    auto num = k % 1000 * 10 + j;
                    if(count[index][num] == 0) {
                        valid[index].emplace_back(num);
                    }
                    count[index][num] = (count[index][num] + count[1 - index][k]) % MOD;
                    dp[i] = (dp[i] + count[1 - index][k]) % MOD;
                }
            }
        }
        for(auto& i : valid[1 - index]) {
            count[1 - index][i] = 0;
        }
        valid[1 - index].clear();
    }
    for(auto& i : queries) {
        cout << dp[i] << endl;
    }
    return 0;
}
