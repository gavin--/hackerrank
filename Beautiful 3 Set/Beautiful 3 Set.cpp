#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = 2 * n / 3, y = 2 * k - n, x = n - 2 * y;
    cout << k + 1 << '\n';
    for (int i = 0; i <= y; i++) {
        cout << i << ' ' << x + i << ' ' << n - x - 2 * i << '\n';
    }
    for (int i = 0; i < k - y; i++) {
        cout << y + i + 1 << ' ' << i << ' ' << n - y - 1 - 2 * i << '\n';
    }
    return 0;
}
