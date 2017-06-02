#include <iostream>
#include <array>
using namespace std;

const long long MOD = 1000000007;

array<array<long long, 3>, 3> multiply(array<array<long long, 3>, 3>& a, array<array<long long, 3>, 3>& b) {
    array<array<long long, 3>, 3> result;
    for(auto i = 0; i < 3; i++) {
        for(auto j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(auto k = 0; k < 3; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

array<array<long long, 3>, 3> pow(array<array<long long, 3>, 3> x, long long n) {
    array<array<long long, 3>, 3> result {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
    while(n > 0) {
        if(n % 2 == 1) {
            result = multiply(result, x);
        }
        x = multiply(x, x);
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; cout << endl) {
        auto result = pow(array<array<long long, 3>, 3> {{{1, 0, 1}, {1, 0, 0}, {0, 1, 0}}}, N - 2);
        cout << (result[0][0] * 3 + result[0][1] * 2 + result[0][2]) % MOD;
    }
    return 0;
}
