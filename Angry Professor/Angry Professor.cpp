#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; ) {
        int count = 0;
        for(int i = 0, j; i != n; i++) {
            cin >> j;
            if(j <= 0) {
                count++;
            }
        }
        if(count < k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
