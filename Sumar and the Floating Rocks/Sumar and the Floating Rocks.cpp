#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    for(int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; cout << endl) {
        auto top = abs(y2 - y1), bottom = abs(x2 - x1);
        if(top == 0) {
            cout << bottom - 1;
        } else if(bottom == 0) {
            cout << top - 1;
        } else {
            cout << gcd(top, bottom) - 1;
        }
    }
    return 0;
}
