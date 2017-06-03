#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int x[T], y[T];
    for(int a, b, i = 0; cin >> a >> b; i++) {
        x[i] = a;
        y[i] = b;
    }
    cout << (long long)(*min_element(x, x + T)) * (*min_element(y, y + T)); 
    return 0;
}
