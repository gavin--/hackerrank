#include <iostream>
#include <vector>
using namespace std;

const long long SIZE = 1000001;

int main() {
    vector<long long> primes;
    vector<bool> prime(SIZE, true);
    for(long long i = 2; i * i < SIZE; i++) {
        if(prime[i]) {
            for(long long j = i * i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }
    for(long long i = 2; i < SIZE; i++) {
        if(prime[i]) {
            primes.emplace_back(i);
        }
    }
    long long n, result = 0;
    cin >> n;
    for(long long a; cin >> a; result++) {
        vector<long long> factors;
        for(auto p : primes) {
            while(a % p == 0) {
                factors.emplace_back(p);
                a /= p;
            }
        }
        if(a > 1) {
            factors.emplace_back(a);
        }
        long long prev = 1;
        for(auto it = factors.rbegin(); it != factors.rend(); it++) {
            result += prev * *it;
            prev *= *it;
        }
    }
    cout << result;
    return 0;
}
