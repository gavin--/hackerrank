#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long N, L0;
    cin >> N;
    cin >> L0;
    for(long long L; cin >> L; ) {
        L0 = (L0 + L + L0 * L) % MOD;
    }
    cout << L0;
    return 0;
}
