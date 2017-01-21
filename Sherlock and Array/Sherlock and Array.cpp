#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, sum = 0;
        cin >> N;
        int A[N];
        for(auto i = 0; i != N; i++) {
            cin >> A[i];
            sum += A[i];
        }
        for(auto i = 0, j = 0; i != N; i++) {
            if(j == sum - j - A[i]) {
                cout << "YES\n";
                goto next;
            }
            j += A[i];
        }
        cout << "NO\n";
        next:
        ;
    }
    return 0;
}
