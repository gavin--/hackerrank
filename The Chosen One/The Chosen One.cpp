#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; cin >> a[i]; i++) {
    }
    if (n == 1) {
        cout << a[0] + 1;
    } else {
        long long prefix[n + 1], postfix = 0;
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = gcd(a[i - 1], prefix[i - 1]);
        }
        for (int i = n; i > 0; i--) {
            auto g = gcd(prefix[i - 1], postfix);
            if (a[i - 1] % g != 0) {
                cout << g;
                break;
            }
            postfix = gcd(a[i - 1], postfix);
        }
    }
    return 0;
}
