#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(int a, b, d; cin >> a >> b >> d; ) {
        if(d == a) {
            cout << 1;
        } else if(d < b && d != 0) {
            cout << 2;
        } else if(d % b == 0) {
            cout << d / b;
        } else {
            cout << d / b + 1;
        }
        cout << endl;
    }
    return 0;
}
