#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, result = INT_MAX;
    cin >> n;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + n);
    for(auto i = 1; i != n; i++) {
        result = min(result, a[i] - a[i - 1]);
    }
    cout << result;
    return 0;
}
