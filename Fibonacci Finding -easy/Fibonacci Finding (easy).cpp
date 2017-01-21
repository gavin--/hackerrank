#include <array>
#include <iostream>
using namespace std;

const int MOD = 1000000007;

array<array<long long, 2>, 2> mul(array<array<long long, 2>, 2>& a, array<array<long long, 2>, 2>& b) {
    array<array<long long, 2>, 2> result;
    result[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    result[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    result[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    result[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    return result;
}

array<array<long long, 2>, 2> pow(array<array<long long, 2>, 2> a, int N) {
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

int fib(long long A, long long B, int N) {
    array<array<long long, 2>, 2> m = {{{1, 1}, {1, 0}}};
    auto a = pow(m, N);
    return (a[1][0] * B + a[1][1] * A) % MOD;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int A, B, N;
        cin >> A >> B >> N;
        cout << fib(A, B, N) << endl;
    }
    return 0;
}
