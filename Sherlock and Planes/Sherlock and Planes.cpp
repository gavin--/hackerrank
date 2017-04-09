#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int x[4], y[4], z[4];
        cin >> x[0] >> y[0] >> z[0];
        vector<bool> same {1, 1, 1};
        for(auto i = 1; i != 4; i++) {
            cin >> x[i] >> y[i] >> z[i];
            if(x[i] != x[i - 1]) {
                same[0] = 0;
            }
            if(y[i] != y[i - 1]) {
                same[1] = 0;
            }
            if(z[i] != z[i - 1]) {
                same[2] = 0;
            }
        }
        if(same[0] || same[1] || same[2]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
