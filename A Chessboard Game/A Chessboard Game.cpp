#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int x, y; cin >> x >> y; ) {
        auto r1 = x % 4, r2 = y % 4;
        if((r1 == 1 || r1 == 2) && (r2 == 1 || r2 == 2)) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    }
    return 0;
}
