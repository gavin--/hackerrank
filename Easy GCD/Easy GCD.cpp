#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n, k, g = 0, result = 0;
    cin >> n >> k;
    for (int a; cin >> a; ) {
        g = gcd(g, a);
    }
    for (int i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            if (i <= k) {
                result = max(result, k / i * i);
            }
            if (g / i <= k) {
                result = max(result, k / (g / i) * i);
            }
        }
    }
    if (g <= k) {
        result = max(result, k / g * g);
    }
    cout << result;
    return 0;
}
