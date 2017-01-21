#include <iostream>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    int a[n];
    for(auto i = 0; i != n; i++) {
        cin >> a[i];
    }
    for(int m; cin >> m; ) {
        cout << a[((m - k) % n + n) % n] << endl;
    }
    return 0;
}
