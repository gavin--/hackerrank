#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int x, y;
        cin >> x >> y;
        auto r1 = (x - 1) % 4, r2 = (y - 1) % 4;
        if((r1 == 0 || r1 == 1) && (r2 == 0 || r2 == 1)) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    }
    return 0;
}
