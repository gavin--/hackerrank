#include <iostream>
using namespace std;

int main() {
    int q;
    for(cin >> q; q > 0; q--) {
        int n, result = 0;
        cin >> n;
        short m[2 * n][2 * n];
        for(auto i = 0; i != 2 * n; i++) {
            for(auto j = 0; j != 2 * n; j++) {
                cin >> m[i][j];
            }
        }
        for(auto i = 0; i != n; i++) {
            for(auto j = 0; j != n; j++) {
                result += max(m[i][j], max(m[2 * n - i - 1][j], max(m[i][2 * n - j - 1], m[2 * n - i - 1][2 * n - j - 1])));
            }
        }
        cout << result << endl;
    }
    return 0;
}
