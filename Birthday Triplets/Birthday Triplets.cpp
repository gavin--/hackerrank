#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

long long sqrt(long long n) {
    auto begin = 0ll, end = n;
    while(begin < end) {
        auto mid = (end + begin) / 2;
        if(mid < n / mid) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

long long sum(long long a, long long l, long long r) {
    if(a == 1) {
        return (r - l + 1) % MOD;
    }
    return pow(a, l) * (pow(a, r - l + 1) - 1) % MOD * pow(a - 1, MOD - 2) % MOD;
}

int main() {
    int q;
    cin >> q;
    for(long long f2, f3, f4, l, r; cin >> f2 >> f3 >> f4 >> l >> r; ) {
        for(auto a = 1ll; ; a++) {
            auto a2 = a * a, a3 = a2 * a, a4 = a2 * a2;
            auto r2 = f2 - a2, r3 = f3 - a3, r4 = f4 - a4;
            auto temp = 2 * r4 - r2 * r2;
            auto discriminant = sqrt(temp);
            if(discriminant * discriminant != temp) {
                continue;
            }
            long long roots[2] = {sqrt((r2 + discriminant) / 2), sqrt((r2 - discriminant) / 2)};
            for(auto i = 0; i <= 1; i++) {
                auto b = roots[i], c = roots[1 - i];
                auto b2 = b * b, b3 = b2 * b, b4 = b * b3;
                auto c2 = c * c, c3 = c2 * c, c4 = c * c3;
                if(a < b < c && a2 + b2 + c2 == f2 && a3 + b3 + c3 == f3 && a4 + b4 + c4 == f4) {
                    cout << (sum(a, l, r) + sum(b, l, r) + sum(c, l, r)) % MOD << endl;
                    goto next;
                }
            }
        }
        next:
            ;
    }
    return 0;
}
