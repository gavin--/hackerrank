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

array<array<long long, 2>, 2> mul(array<array<long long, 2>, 2>& a, array<array<long long, 2>, 2>& b) {
    array<array<long long, 2>, 2> result;
    result[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    result[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    result[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    result[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    return result;
}

array<array<long long, 2>, 2> pow(array<array<long long, 2>, 2> a, long long N) {
    array<array<long long, 2>, 2> result = {{{1, 0}, {0, 1}}};
    while(N != 0) {
        if(N % 2 == 1) {
            result = mul(result, a);
        }
        N /= 2;
        a = mul(a, a);
    }
    return result;
}

int fib(long long N) {
    array<array<long long, 2>, 2> m = {{{1, 1}, {1, 0}}};
    auto a = pow(m, N - 1);
    return (a[1][0] + a[1][1]) % MOD;
}

int main() {
    int N;
    cin >> N;
    long long result;
    cin >> result;
    for(long long i; cin >> i; ) {
        result = gcd(result, i);
    }
    cout << fib(result);
    return 0;
}
