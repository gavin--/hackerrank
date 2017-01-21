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
    for(cin >> T; T > 0; T--) {
        int x1, y1, x2, y2, result;
        cin >> x1 >> y1 >> x2 >> y2;
        auto top = abs(y2 - y1), bottom = abs(x2 - x1);
        if(top == 0) {
            result = bottom - 1;
        } else if(bottom == 0) {
            result = top - 1;
        } else {
            result = gcd(top, bottom) - 1;
        }
        cout << result << endl;
    }
    return 0;
}
