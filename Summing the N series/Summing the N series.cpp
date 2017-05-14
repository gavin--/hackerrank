#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(long long n; cin >> n; cout << n % MOD * (n % MOD) % MOD << endl) {
    }
    return 0;
}
