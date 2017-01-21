#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + n);
    for(auto& i : a) {
        cout << i << ' ';
    }
    return 0;
}
