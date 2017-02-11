#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long S;
        cin >> S;
        if(S % 20 == 0) {
            cout << (S / 20 * 42 - 2) % MOD;
        } else {
            cout << (S / 20 * 42 + S % 20 * 2) % MOD;
        }
        cout << endl;
    }
    return 0;
}
