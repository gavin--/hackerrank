#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    auto E = 99;
    bool c[n];
    for(auto i = 0; i != n; i++) {
        cin >> c[i];
    }
    if(c[0]) {
        E -= 2;
    }
    for(auto i = k % n; i != 0; i = (i + k) % n) {
        if(c[i]) {
            E -= 2;
        }
        E--;
    }
    cout << E;
    return 0;
}
