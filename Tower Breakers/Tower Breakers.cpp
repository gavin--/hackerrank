#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, M;
        cin >> N >> M;
        if(N % 2 == 0 || M == 1) {
            cout << 2;
        } else {
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}
