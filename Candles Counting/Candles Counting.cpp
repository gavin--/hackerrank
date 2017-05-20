#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int lowbit(int i) {
    return i & -i;
}

void add(vector<int>& dp, int i, int j) {
    while(i < dp.size()) {
        dp[i] = (dp[i] + j) % MOD;
        i += lowbit(i);
    }
}

int sum(vector<int>& dp, int i) {
    auto sum = 0;
    while(i > 0) {
        sum = (sum + dp[i]) % MOD;
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int N, K, max = 0;
    cin >> N >> K;
    int H[N], C[N], size = 1 << K;
    for(auto i = 0; cin >> H[i] >> C[i]; i++) {
        C[i]--;
        if(max < H[i]) {
            max = H[i];
        }
    }
    vector<int> dp[size];
    for(auto i = 0; i < size; i++) {
        dp[i] = vector<int>(max + 1, 0);
    }
    for(auto i = 0; i < N; i++) {
        for(auto j = 0; j < size; j++) {
            if((j & (1 << C[i])) != 0) {
                add(dp[j], H[i], sum(dp[j ^ (1 << C[i])], H[i] - 1));
            } else {
                add(dp[j], H[i], sum(dp[j], H[i] - 1));
            }
        }
        add(dp[0], H[i], 1);
        add(dp[1 << C[i]], H[i], 1);
    }
    cout << sum(dp[size - 1], max);
    return 0;
}
