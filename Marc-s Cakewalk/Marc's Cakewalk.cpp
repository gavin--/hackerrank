#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c[n];
    long long result = 0;
    for(auto i = 0; cin >> c[i]; i++) {
    }
    sort(c, c + n, greater<int>());
    for(auto i = 0; i != n; i++) {
        result += (1ll << i) * c[i];
    }
    cout << result;
    return 0;
}
