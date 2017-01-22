#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    int X[N];
    long long sum[N + 1];
    sum[0] = 0;
    for(auto i = 0; cin >> X[i]; i++) {
    }
    sort(X, X + N);
    for(auto i = 0; i != N; i++) {
        sum[i + 1] = sum[i] + X[i];
    }
    auto result = 0ll;
    for(auto j = 1ll, dp = 0ll; j < K; j++) {
        dp += j * (X[j] - X[j - 1]);
        result += dp;
    }
    auto previous = result;
    for(auto i = 1; i <= N - K; i++) {
        previous += -2 * (sum[i + K - 1] - sum[i]) + (K - 1) * (X[i + K - 1] + X[i - 1]);
        result = min(result, previous);
    }
    cout << result;
    return 0;
}
