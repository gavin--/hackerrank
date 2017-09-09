#include <iostream>
#include <array>
using namespace std;

array<array<long long, 2>, 2> mul(array<array<long long, 2>, 2>& a, array<array<long long, 2>, 2>& b, long long m) {
    array<array<long long, 2>, 2> result;
    result[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % m;
    result[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % m;
    result[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % m;
    result[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % m;
    return result;
}

array<array<long long, 2>, 2> pow(array<array<long long, 2>, 2> a, long long n, long long m) {
    array<array<long long, 2>, 2> result = {{{1, 0}, {0, 1}}};
    while(n != 0) {
        if(n % 2 == 1) {
            result = mul(result, a, m);
        }
        n /= 2;
        a = mul(a, a, m);
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(long long A, N, M; cin >> A >> N >> M; ) {
        long long L = 1;
        while(L <= A) {
            L *= 10;
        }
        array<array<long long, 2>, 2> x = {{{L, 1}, {0, 1}}};
        x = pow(x, N - 1, M);
        cout << (x[0][0] + x[0][1]) * A % M << endl;
    }
    return 0;
}
