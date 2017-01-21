#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    for(auto i = 0; cin >> x[i] >> y[i]; i++) {
    }
    bool h = 1, v = 1;
    for(auto i = 1; i < n; i++) {
        if(x[i] != x[i - 1]) {
            v = 0;
        }
        if(y[i] != y[i - 1]) {
            h = 0;
        }
    }
    if(h || v) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
