#include <iostream>
#include <vector>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

const long long SIZE = 999984;

bool prime(const vector<long long>& primes, long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long p : primes) {
        if (p * p > n) {
            break;
        }
        if (n % p == 0) {
            return false;
        }
    }
    return true;
}

vector<long long> sieve() {
    vector<long long> prime;
    bool composite[SIZE] = {};
    for (long long i = 2; i < SIZE; i++) {
        if (!composite[i]) {
            prime.emplace_back(i);
        }
        for (long long j = 0; j < prime.size() && i * prime[j] < SIZE; j++) {
            composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return prime;
}

int main() {
    vector<long long> primes = sieve();
    int t;
    cin >> t;
    for (long long n, k; cin >> n >> k; ) {
        if (k == 1) {
            if (prime(primes, n)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else if (k == 2) {
            if (n % 2 == 0 && n != 2 || prime(primes, n - 2)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            if (n < 2 * k) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}
