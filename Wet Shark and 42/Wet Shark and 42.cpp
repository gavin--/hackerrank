#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(long long S; cin >> S; cout << endl) {
        if(S % 20 == 0) {
            cout << (S / 20 * 42 - 2) % MOD;
        } else {
            cout << (S / 20 * 42 + S % 20 * 2) % MOD;
        }
    }
    return 0;
}
