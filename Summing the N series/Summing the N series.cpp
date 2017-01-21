#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long n;
        cin >> n;
        n %= MOD;
        n = n * n % MOD;
        cout << n << endl;
    }
    return 0;
}
