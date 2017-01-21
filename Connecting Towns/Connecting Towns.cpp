#include <iostream>
using namespace std;

const int MOD = 1234567;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, result = 1;
        cin >> N;
        for(auto i = 0; i != N - 1; i++) {
            int d;
            cin >> d;
            result = result * d % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
