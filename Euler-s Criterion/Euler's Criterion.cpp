#include <iostream>
using namespace std;

long long pow(long long x, long long n, long long mod) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % mod;
        }
        n /= 2;
        x = x * x % mod;
    }
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long A, M;
        cin >> A >> M;
        if(pow(A, (M - 1) / 2, M) == 1 || A == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
