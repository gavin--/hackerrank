#include <cmath>
#include <iostream>
using namespace std;

bool sq(int n) {
    int t = floor(sqrt(n));
    if(t * t == n) {
        return true;
    }
    return false;
}

int count(int d) {
    auto result = 0;
    for(auto x = 1; ; x++) {
        auto x2 = x * x, t = 2 * x2;
        if(t >= d) {
            if(t == d) {
                result += 4;
            }
            break;
        }
        if(sq(d - x2)) {
            result += 8;
        }
    }
    if(sq(d)) {
        result += 4;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(int d, k; cin >> d >> k;) {
        if(count(d) <= k) {
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }
    }
    return 0;
}
