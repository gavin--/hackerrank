#include <vector>
#include <iostream>
using namespace std;

const long long MOD = 1000007;

int main() {
    int N;
    cin >> N;
    vector<bool> prime(N + 1, 1);
    for(auto i = 2; i * i <= N; i++) {
        if(prime[i]) {
            for(auto j = i * i; j <= N; j += i) {
                prime[j] = 0;
            }
        }
    }
    auto result = 1ll;
    for(auto i = 2ll; i <= N; i++) {
        if(prime[i]) {
            auto current = 0ll;
            for(auto k = i; k <= N; k *= i) {
                current += N / k;
            }
            result = (result * (2 * current + 1)) % MOD;
        }
    }
    cout << result;
    return 0;
}
