#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
const int SIZE = 1299710;

long long pow(long long x, long long n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

long long inverse(long long n) {
    return pow(n, MOD - 2);
}

long long negative(long long n) {
    return MOD - n;
}

long long sq(long long n) {
    return n * n % MOD;
}

int main() {
    int q;
    cin >> q;
    vector<bool> prime(SIZE, true);
    for(int i = 2; i * i < SIZE; i++) {
        if(prime[i]) {
            for(int j = i * i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for(int i = 2; i < SIZE; i++) {
        if(prime[i]) {
            primes.emplace_back(i);
        }
    }
    for(long long m, a; cin >> m >> a; ) {
        long long result = 1;
        for(long long i = 1; i <= m; i++) {
            long long p = primes[i - 1], inv = inverse(p + negative(1));
            result = result * ((pow(p, a + 1 + i) + negative(1)) % MOD * inv % MOD * p % MOD + negative(a + 1 + i)) % MOD;
            result = result * inv % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
