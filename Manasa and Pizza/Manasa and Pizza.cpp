#include <iostream>
#include <array>
using namespace std;

const long long MOD = 1000000007;

array<array<long long, 2>, 2> mul(array<array<long long, 2>, 2>& a, array<array<long long, 2>, 2>& b) {
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
            result = mul(result, a);
        }
        n /= 2;
        a = mul(a, a);
    }
    return result;
}

long long F(long long n) {
    if(n == 0) {
        return 1;
    }
    auto m = pow({{{6, MOD - 1}, {1, 0}}}, n - 1);
    return (m[0][0] * 3 + m[0][1]) % MOD;
}

int main() {
    long long N, result = 1;
    cin >> N;
    for(long long A; cin >> A; result = 2 * result * F(A) % MOD) {
    }
    cout << result % MOD;
    return 0;
}
