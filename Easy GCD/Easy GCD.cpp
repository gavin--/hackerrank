#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int largest(int g, int k) {
    auto l = g;
    while(l + g <= k) {
        l += g;
    }
    return l;
}

int main() {
    int n, k, g = 0, result = 0;
    cin >> n >> k;
    for(int a; cin >> a; ) {
        g = gcd(g, a);
    }
    for(auto i = 2; i * i <= g; i++) {
        if(g % i == 0) {
            if(i <= k) {
                result = max(result, largest(i, k));
            }
            if(g / i <= k) {
                result = max(result, largest(g / i, k));
            }
        }
    }
    if(g <= k) {
        result = max(result, largest(g, k));
    }
    cout << result;
    return 0;
}
