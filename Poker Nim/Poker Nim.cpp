#include <iostream>
using namespace std;

int main() {
    int g;
    for(cin >> g; g > 0; g--) {
        int n, k, result = 0;
        cin >> n >> k;
        for(auto i = 0; i != n; i++) {
            int j;
            cin >> j;
            result = result ^ j;
        }
        if(result == 0) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    }
    return 0;
}
