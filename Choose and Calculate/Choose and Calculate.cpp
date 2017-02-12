#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

long long* cal(long long N, long long K) {
    long long factorial[N], ifactorial[N], inv[N], *dp = new long long[N];
    factorial[0] = 1;
    ifactorial[0] = 1;
    inv[1] = 1;
    factorial[1] = 1;
    ifactorial[1] = 1;
    dp[K - 2] = 1;
    for(auto i = 2; i < N; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
    }
    for(auto i = K - 1; i < N; i++) {
        dp[i] = (dp[i - 1] + factorial[i] * ifactorial[K - 2] % MOD * ifactorial[i - K + 2]) % MOD;
    }
    return dp;
}

int main() {
    long long N, K;
    cin >> N >> K;
    if(K == 1) {
        cout << 0;
        return 0;
    }
    auto dp = cal(N, K);
    int a[N];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + N);
    auto result = 0ll;
    for(auto i = K - 1; i < N; i++) {
        result = (result + a[i] * dp[i - 1]) % MOD;
    }
    for(auto i = 0; i <= N - K; i++) {
        result = (result - a[i] * dp[N - i - 2]) % MOD;
    }
    cout << (result + MOD) % MOD;
    return 0;
}
