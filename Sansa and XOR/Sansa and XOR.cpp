#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, result = 0;
        cin >> N;
        for(auto i = 0; i != N; i++) {
            int a;
            cin >> a;
            if((i + 1) % 2 * (N - i) % 2 == 1) {
                result = result ^ a;
            }
        }
        cout << result << endl;
    }
    return 0;
}
