#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int n, k; cin >> n >> k; cout << '\n') {
        int result[n];
        bool exist = true, used[n] = {};
        for (int i = 0; i < n; i++) {
            if (i - k >= 0 && used[i - k] == 0) {
                used[i - k] = 1;
                result[i] = i + 1 - k;
            } else if(i + k < n && used[i + k] == 0) {
                used[i + k] = 1;
                result[i] = i + 1 + k;
            } else {
                exist = false;
                break;
            }
        }
        if (exist) {
            for (int i : result) {
                cout << i << ' ';
            }
        } else {
            cout << "-1";
        }
    }
    return 0;
}
