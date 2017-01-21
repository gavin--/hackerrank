#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long exp(long long x, long long n) {
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
    int N;
    cin >> N;
    auto even = 0ll, odd = 0ll;
    for(int i; cin >> i; ) {
        if(i % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    cout << ((exp(2, even) * exp(2, odd - 1) - 1) % MOD + MOD) % MOD;
    return 0;
}
