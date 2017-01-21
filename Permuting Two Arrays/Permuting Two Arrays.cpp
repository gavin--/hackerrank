#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q > 0) {
        q--;
        int n, k;
        cin >> n >> k;
        int A[n], B[n];
        for(auto i = 0; i != n; i++) {
            cin >> A[i];
        }
        for(auto i = 0; i != n; i++) {
            cin >> B[i];
        }
        sort(A, A + n);
        sort(B, B + n, greater<int>());
        for(auto i = 0; i != n; i++) {
            if(A[i] + B[i] < k) {
                cout << "NO\n";
                goto next;
            }
        }
        cout << "YES\n";
        next:
        ;
    }
    return 0;
}
