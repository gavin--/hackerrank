#include <iostream>
#include <array>
using namespace std;

array<long long, 2> multiply(array<long long, 2>& a, array<long long, 2>& b, long long m) {
    return array<long long, 2> {(a[0] * b[0] - a[1] * b[1]) % m, (a[0] * b[1] + b[0] * a[1]) % m};
}

array<long long, 2> pow(array<long long, 2>& n, long long k, long long m) {
    array<long long, 2> result = {1, 0};
    while(k != 0) {
        if(k % 2 == 1) {
            result = multiply(result, n, m);
        }
        n = multiply(n, n, m);
        k /= 2;
    }
    result[0] = (result[0] + m) % m;
    result[1] = (result[1] + m) % m;
    return result;
}

int main() {
    int q;
    cin >> q;
    for(array<long long, 2> n; cin >> n[0] >> n[1]; ) {
        long long k, m;
        cin >> k >> m;
        auto result = pow(n, k, m);
        cout << result[0] << ' ' << result[1] << endl;
    }
    return 0;
}
