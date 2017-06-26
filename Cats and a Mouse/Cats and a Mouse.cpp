#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(int x, y, z; cin >> x >> y >> z; ) {
        if(abs(z - y) > abs(z - x)) {
            cout << "Cat A\n";
        } else if (abs(z - y) < abs(z - x)) {
            cout << "Cat B\n";
        } else {
            cout << "Mouse C\n";
        }
    }
    return 0;
}
