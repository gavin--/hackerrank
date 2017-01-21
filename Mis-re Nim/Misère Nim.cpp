#include <iostream>
using namespace std;

int main() {
    int g;
    for(cin >> g; g > 0; g--) {
        int n, result = 0, m = 0;
        cin >> n;
        for(auto i = 0; i != n; i++) {
            int j;
            cin >> j;
            result = result ^ j;
            m = max(j, m);
        }
        if(m > 1) {
            if(result == 0) {
                cout << "Second\n";
            } else {
                cout << "First\n";
            }
        } else {
            if(result == 0) {
                cout << "First\n";
            } else {
                cout << "Second\n";
            }
        }
    }
    return 0;
}
