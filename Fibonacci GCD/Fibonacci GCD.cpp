#include <iostream>
#include <array>
using namespace std;

const long long MOD = 1000000007;

long long gcd(long long a, long long b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

array<array<long long, 2>, 2> multiply(array<array<long long, 2>, 2>& a, array<array<long long, 2>, 2>& b) {
    array<array<long long, 2>, 2> result;
    result[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    result[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    result[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    result[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    return result;
}

array<array<long long, 2>, 2> pow(array<array<long long, 2>, 2> a, long long n) {
    array<array<long long, 2>, 2> result = {{{1, 0}, {0, 1}}};
    while(n != 0) {
        if(n % 2 == 1) {
            result = multiply(result, a);
        }
        n /= 2;
        a = multiply(a, a);
    }
    return result;
}

int fib(long long n) {
    array<array<long long, 2>, 2> m = {{{1, 1}, {1, 0}}};
    auto result = pow(m, n - 1);
    return (result[1][0] + result[1][1]) % MOD;
}

int main() {
    int N;
    cin >> N;
    long long result;
    cin >> result;
    for(long long i; cin >> i; result = gcd(result, i)) {
    }
    cout << fib(result);
    return 0;
}
