#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + n);
    auto result = 0ll;
    for(auto i = 0ll, j = n; i < n / 2; i++) {
        if(k > j - k) {
            result += (a[n - i - 1] - a[i]) * (j - k);
            j -= 2;
            k -= 2;
        } else {
            result += (a[n - i - 1] - a[i]) * k;
            j -= 2;
        }
    }
    cout << result;
    return 0;
}
