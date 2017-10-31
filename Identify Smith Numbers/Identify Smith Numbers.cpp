#include <iostream>
using namespace std;

int sum(int n) {
    int digits = 0;
    do {
        digits += n % 10;
        n /= 10;
    } while(n > 0);
    return digits;
}

int main() {
    int N, primes = 0;
    cin >> N;
    int digits = sum(N);
    for(int i = 2; i <= N / i; i++) {
        while(N % i == 0) {
            primes += sum(i);
            N /= i;
        }
    }
    if(N > 1) {
        primes += sum(N);
    }
    cout << (digits == primes);
    return 0;
}
