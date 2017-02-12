#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    rotate(a, a + d, a + n);
    for(auto i = 0; i != n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
