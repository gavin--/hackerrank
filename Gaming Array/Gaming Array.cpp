#include <iostream>
using namespace std;

int main() {
    int g;
    for(cin >> g; g > 0; g--) {
        bool bob = false;
        int n;
        cin >> n;
        for(auto i = 0, max = 0; i != n; i++) {
            int j;
            cin >> j;
            if(j > max) {
                max = j;
                bob = !bob;
            }
        }
        if(bob) {
            cout << "BOB\n";
        } else {
            cout << "ANDY\n";
        }
    }
    return 0;
}
