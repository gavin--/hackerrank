#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int q;
    cin >> q;
    vector<bool> prime(8192, true);
    for(auto i = 2; i * i < 8192; i++) {
        if(prime[i]) {
            for(auto j = i * i; j < 8192; j += i) {
                prime[j] = false;
            }
        }
    }
    for(int n; cin >> n; ) {
        int map[1001] = {};
        for(int a; n > 0; n--) {
            cin >> a;
            map[a - 3500]++;
        }
        vector<int> a;
        for(auto i = 0; i < 1001; i++) {
            if(map[i] > 0) {
                a.emplace_back(i + 3500);
            }
        }
        int dp[a.size() + 1][8192], result = 0;
        dp[0][0] = 1;
        fill(dp[0] + 1, dp[0] + 8192, 0);
        for(auto i = 1; i <= a.size(); i++) {
            for(auto j = 0; j < 8192; j++) {
                dp[i][j] = ((long long)dp[i - 1][j] * ((map[a[i - 1] - 3500] + 2) / 2) + (long long)dp[i - 1][a[i - 1] ^ j] * ((map[a[i - 1] - 3500] + 1) / 2)) % MOD;
            }
        }
        for(auto i = 2; i < 8192; i++) {
            if(prime[i]) {
                result = (result + dp[a.size()][i]) % MOD;
            }
        }
        cout << result << endl;
    }
    return 0;
}
