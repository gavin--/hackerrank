#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int x[4], y[4], z[4];
        cin >> x[0] >> y[0] >> z[0];
        cin >> x[1] >> y[1] >> z[1];
        cin >> x[2] >> y[2] >> z[2];
        cin >> x[3] >> y[3] >> z[3];
        bool same[] = {1, 1, 1};
        for(auto i = 1; i != 4; i++) {
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
