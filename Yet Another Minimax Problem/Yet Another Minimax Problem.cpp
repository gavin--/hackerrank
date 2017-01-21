#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, result = INT_MAX;
    cin >> n;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + n);
    if(a[n - 1] == a[0]) {
        cout << 0;
        return 0;
    }
    auto low = 1;
    while(low * 2 <= a[n - 1]) {
        low *= 2;
    }
    while(a[0] >= low) {
        for(auto i = 0; i != n; i++) {
            a[i] -= low;
        }
        low = 1;
        while(low * 2 <= a[n - 1]) {
            low *= 2;
        }
    }
    auto i = 1;
    for(; i < n; i++) {
        if(a[i] >= low) {
            break;
        }
    }
    for(auto j = 0; j < i; j++) {
        for(auto k = i; k < n; k++) {
            result = min(result, a[j] ^ a[k]);
        }
    }
    cout << result;
    return 0;
}
