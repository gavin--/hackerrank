#include <iostream>
using namespace std;

const long long MOD = 1000000007, INV = 500000004, SIZE = 200001;

long long pow(long long x, long long n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int D;
    cin >> D;
    long long factorial[SIZE], ifactorial[SIZE], inv[SIZE];
    inv[1] = 1;
    factorial[0] = 1;
    factorial[1] = 1;
    ifactorial[0] = 1;
    ifactorial[1] = 1;
    for(long long i = 2; i < SIZE; i++) {
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        factorial[i] = factorial[i - 1] * i % MOD;
        ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
    }
    for(long long m, a; cin >> m >> a; ) {
        long long result = (a + 2) * (a + m + 2) % MOD;
        long long t = factorial[a + m + 1] * ifactorial[a + 2] % MOD;
        result = result * t % MOD * t % MOD;
        cout << result * pow(INV, m) % MOD << endl;
    }
    return 0;
}
