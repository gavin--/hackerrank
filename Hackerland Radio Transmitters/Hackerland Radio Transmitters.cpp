#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, result = 0;
    cin >> n >> k;
    int x[n];
    for(auto i = 0; cin >> x[i]; i++) {
    }
    sort(x, x + n);
    for(auto i = 0; i < n; i++) {
        auto j = i;
        while(j + 1 < n && x[j + 1] - x[i] <= k) {
            j++;
        }
        i = j;
        while(i + 1 < n && x[i + 1] - x[j] <= k) {
            i++;
        }
        result++;
    }
    cout << result;
    return 0;
}
