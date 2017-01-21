#include <iostream>
using namespace std;

int sum(int N) {
    auto digits = 0;
    for(auto i = N; i > 0; i /= 10) {
        digits += i % 10;
    }
    return digits;
}

int main() {
    int N, primes = 0;
    cin >> N;
    auto digits = sum(N);
    for(auto i = 2; i <= N / i; i++) {
        while(N % i == 0) {
            primes += sum(i);
            N /= i;
        }
    }
    if(N > 1) {
        primes += sum(N);
    }
    if(digits == primes) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
