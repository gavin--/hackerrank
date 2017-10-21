#include <iostream>
#include <climits>
#include <tuple>
using namespace std;

tuple<long long, long long, long long> egcd(long long a, long long b) {
    pair<long long, long long> s(1, 0), t(0, 1), r(a, b);
    while(r.second != 0) {
        auto q = r.first / r.second;
        r = {r.second, r.first - q * r.second};
        s = {s.second, s.first - q * s.second};
        t = {t.second, t.first - q * t.second};
    }
    return {s.first, t.first, r.first};
}

long long sq(long long n) {
    return n * n;
}

long long floor(long long a, long long b) {
    if((a < 0 && b > 0) || (a > 0 && b < 0)) {
        a = abs(a), b = abs(b);
        return -((a - 1) / b + 1);
    }
    return a / b;
}

int main() {
    int q;
    cin >> q;
    for(long long a, b, c; cin >> a >> b >> c; ) {
        auto g = egcd(a, b);
        pair<long long, long long> result;
        long long gcd = get<2>(g), d = LLONG_MAX, u = a / gcd, v = b / gcd;
        long long x = get<0>(g) * c / gcd, y = get<1>(g) * c / gcd;
        long long k = floor(a * c / (sq(a) + sq(b)) - x, v);
        if(x + k * v > 0) {
            d = sq(x + k * v) + sq(y - k * u);
            result = {x + k * v, y - k * u};
        }
        if(sq(x + (k + 1) * v) + sq(y - (k + 1) * u) < d) {
            result = {x + (k + 1) * v, y - (k + 1) * u};
        }
        cout << result.first << ' ' << result.second << endl;
    }
    return 0;
}
