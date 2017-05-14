#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; cout << (pow(2, N + 1) + 2) % MOD << endl) {
    }
    return 0;
}
