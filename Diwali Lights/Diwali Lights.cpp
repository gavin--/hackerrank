#include <iostream>
using namespace std;

const long long MOD = 100000;

int pow(long long x, int n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        cout << pow(2, N) - 1 << endl;
    }
    return 0;
}
