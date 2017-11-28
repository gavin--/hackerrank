#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int a[n], result = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            if(a[i] - i > 3) {
                result = -1;
                break;
            }
            for(int j = max(0, a[i] - 2); j < i; j++) {
                if(a[j] > a[i]) {
                    result++;
                }
            }
        }
        if(result == -1) {
            cout << "Too chaotic\n";
        } else {
            cout << result << endl;
        }
    }
    return 0;
}
