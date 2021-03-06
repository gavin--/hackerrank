#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
long long *factorial, *ifactorial;

void precompute(long long n, long long k) {
    factorial = new long long[n], ifactorial = new long long[n];
    long long inv[n];
    factorial[0] = 1;
    ifactorial[0] = 1;
    inv[1] = 1;
    factorial[1] = 1;
    ifactorial[1] = 1;
    for (long long i = 2; i < n; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
    }
}

long long binomial(long long n, long long k) {
    return factorial[n] * ifactorial[k] % MOD * ifactorial[n - k] % MOD;
}

int main() {
    long long N, K;
    cin >> N >> K;
    precompute(N, K);
    int a[N];
    for (int i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + N);
    long long result = 0;
    for (long long i = K - 1; i < N; i++) {
        result = (result + a[i] * binomial(i, K - 1)) % MOD;
    }
    for (long long i = 0; i <= N - K; i++) {
        result = (result - a[i] * binomial(N - i - 1, K - 1)) % MOD;
    }
    cout << (result + MOD) % MOD;
    return 0;
}
