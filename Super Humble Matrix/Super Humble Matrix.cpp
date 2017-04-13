#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long N, M, result = 1;
    cin >> N >> M;
    long long factorial[min(N, M) + 1];
    factorial[0] = 1;
    for(auto i = 1ll; i <= min(N, M); i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    for(auto i = 1ll; i < N; i++) {
        result = result * factorial[min(i, M)] % MOD;
    }
    for(auto i = 0ll; i < M; i++) {
        result = result * factorial[min(N, M - i)] % MOD;
    }
    cout << result;
    return 0;
}
