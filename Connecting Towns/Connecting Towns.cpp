#include <iostream>
using namespace std;

const int MOD = 1234567;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int result = 1;
        for(auto i = 0; i != N - 1; i++) {
            int d;
            cin >> d;
            result = result * d % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
