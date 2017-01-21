#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++){
    }
    sort(a, a + n);
    for(auto i = n - 1; i >= 2; i--) {
        if(a[i - 2] + a[i - 1] > a[i]) {
            cout << a[i - 2] << ' ' << a[i - 1] << ' ' << a[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
