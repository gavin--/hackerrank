#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, K;
        cin >> N >> K;
        for(auto i = N - 1, j = 0; ; j++) {
            if(i == K) {
                cout << j << endl;
                break;
            }
            if(j % 2 == 0) {
                i = N - 1 - i;
            } else {
                i = N - 2 - i;
            }
        }
    }
    return 0;
}
