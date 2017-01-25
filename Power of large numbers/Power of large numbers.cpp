#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string a, b;
        cin >> a >> b;
        long long A = (a[0] - '0') % MOD, B = (b[0] - '0') % (MOD - 1);
        for(auto i = 1; i < a.size(); i++) {
            A = (A * 10 + a[i] - '0') % MOD;
        }
        for(auto i = 1; i < b.size(); i++) {
            B = (B * 10 + b[i] - '0') % (MOD - 1);
        }
        cout << pow(A, B) << endl;
    }
    return 0;
}
