#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int c[n];
    auto result = LLONG_MAX;
    for(auto i = 0; cin >> c[i]; i++) {
    }
    for(auto i = 0; i <= min(n - 1, k); i++) {
        auto remaining = (n - i - k - 1) % (2 * k + 1);
        if(remaining > k || remaining <= 0) {
            auto current = 0ll;
            for(auto j = i; j < n; j += 2 * k + 1) {
                current += c[j];
            }
            result = min(result, current);
        }
    }
    cout << result;
    return 0;
}
