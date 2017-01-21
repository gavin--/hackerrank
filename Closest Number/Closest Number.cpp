#include <iostream>
using namespace std;

int pow(int x, int n) {
    auto result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int a, b, x;
        cin >> a >> b >> x;
        if(b < 0) {
            if(a == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
            cout << endl;
            continue;
        }
        auto ab = pow(a, b);
        if(ab - ab / x * x <= (ab / x + 1) * x - ab) {
            cout << ab / x * x;
        } else {
            cout << (ab / x + 1) * x;
        }
        cout << endl;
    }
    return 0;
}
