#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, K;
        cin >> N >> K;
        auto count = 0;
        for(auto i = 0; i != N; i++) {
            int j;
            cin >> j;
            if(j <= 0) {
                count++;
            }
        }
        if(count < K) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
