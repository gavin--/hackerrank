#include <vector>
#include <iostream>
using namespace std;

long long pow(long long x, int n, int p) {
    auto result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = (result * x) % p;
        }
        x = (x * x) % p;
        n /= 2;
    }
    return result;
}

vector<int> factor(int n) {
    vector<int> primes;
    for(auto i = 2; i <= n / i; i++) {
        if(n % i == 0) {
            primes.emplace_back(i);
        }
        while(n % i == 0) {
            n /= i;
        }
    }
    if(n > 1) {
        primes.emplace_back(n);
    }
    return primes;
}

int main() {
    int p;
    cin >> p;
    vector<int> primes = factor(p - 1);
    for(auto i = 2; ; i++) {
        auto root = true;
        for(auto& j : primes) {
            if(pow(i, (p - 1) / j, p) == 1) {
                root = false;
                break;
            }
        }
        if(root) {
            cout << i << ' ';
            break;
        }
    }
    auto roots = p - 1;
    for(auto& i : primes) {
        roots /= i;
        roots *= i - 1;
    }
    cout << roots;
    return 0;
}
