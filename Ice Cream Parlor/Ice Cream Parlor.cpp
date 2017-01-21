#include <iostream>
using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, m;
        cin >> m >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(auto i = 0; i != n; i++) {
            for(auto j = 0; j != i; j++) {
                if(arr[i] + arr[j] == m) {
                    cout << j + 1 << ' ' << i + 1 << endl;
                    goto next;
                }
            }
        }
        next:
        ;
    }
    return 0;
}
