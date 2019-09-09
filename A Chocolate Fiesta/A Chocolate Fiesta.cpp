#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    long long result = 1;
    while (n != 0) {
        if (n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    long long parity[2] = {};
    for (int i; cin >> i; parity[i % 2]++) {
    }
    cout << (pow(2, parity[0]) * pow(2, parity[1] - 1) + MOD - 1) % MOD;
    return 0;
}
