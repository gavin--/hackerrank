#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    int A[N];
    for(auto i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for(int x, y; cin >> x >> y; ) {
        if(A[x - 1] % 2 == 1 || y > x && A[x] == 0) {
            cout << "Odd\n";
        } else {
            cout << "Even\n";
        }
    }
    return 0;
}
